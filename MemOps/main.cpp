
#include <AMReX.H>
#include <AMReX_Print.H>
#include <AMReX_Utility.H>
#include <AMReX_Gpu.H>

#include <thread>
#include <future>

#ifndef AMREX_USE_GPU
#error This test is for CUDA only.
#endif

#define CU_CHECK(stmt)                                                            \
    do {                                                                          \
        CUresult result = (stmt);                                                 \
        if (CUDA_SUCCESS != result) {                                             \
            const char *str;                                                      \
            CUresult str_result = cuGetErrorString(result, &str);                 \
            if (str_result != CUDA_SUCCESS)                                       \
                fprintf(stderr, "[%s:%d] cu failed with unknown error %d\n",      \
                        __FILE__, __LINE__, result);                              \
            else                                                                  \
                fprintf(stderr, "[%s:%d] cu failed with %s \n",                   \
                        __FILE__, __LINE__, str);                                 \
            exit(-1);                                                             \
        }                                                                         \
    } while (0)

struct gpu_promise {
    char id;
    double sleep;
    double tz;
    std::promise<void> timestep;
};

struct gpu_basic {
    char id;
    double sleep;
    double tz;
};

// ......................

// Mocking GPU callback function work
void CUDART_CB do_step_gpu_promise(void* p)
{
    auto p_prom = reinterpret_cast<gpu_promise*>(p);

    amrex::Print() << "Beginning GPU work on " << p_prom->id <<
                      " at " << amrex::second() - p_prom->tz << std::endl;
    amrex::Sleep(p_prom->sleep);
    amrex::Print() << "Ending GPU work on " << p_prom->id <<
                      " at " << amrex::second() - p_prom->tz << std::endl;

    p_prom->timestep.set_value();
    delete p_prom;
}

// Mocking GPU callback function work
void CUDART_CB do_step_gpu(void* p)
{
    auto p_basic = reinterpret_cast<gpu_basic*>(p);

    amrex::Print() << "Beginning GPU work on " << p_basic->id <<
                      " at " << amrex::second() - p_basic->tz << std::endl;
    amrex::Sleep(p_basic->sleep);
    amrex::Print() << "Ending GPU work at " << p_basic->id <<
                      " at " << amrex::second() - p_basic->tz << std::endl;

    delete p_basic;
}

// ......................

// Mocking CPU thread work
void do_step_promise (double sleep, double time_zero, std::promise<void> timestep)
{
    amrex::Print() << "Beginning thread work at " << amrex::second() - time_zero << std::endl;
    amrex::Sleep(sleep);
    amrex::Print() << "Ending thread work at " << amrex::second() - time_zero << std::endl;

    timestep.set_value();
}

// Mocking primary thread work
void do_step (double sleep, double time_zero)
{
    amrex::Print() << "Beginning host work at " << amrex::second() - time_zero << std::endl;
    amrex::Sleep(sleep);
    amrex::Print() << "Ending host work at " << amrex::second() - time_zero << std::endl;
}

// ......................

int main(int argc, char* argv[])
{
    amrex::Initialize(argc,argv);
    {
        amrex::Print() << "Hello world from AMReX version " << amrex::Version() << "\n";

        int max_step = 3;

        double sleep_ns = 0.5*1e9;
        double sleep_host = 0.1;
        double time_zero = amrex::second();

        const int max_streams = amrex::Gpu::Device::numGpuStreams();
        std::vector<amrex::gpuStream_t> streams(max_streams);
        for (int i=0; i<max_streams; ++i)
        {
            amrex::Gpu::Device::setStreamIndex(i);
            streams[i] = amrex::Gpu::gpuStream();
        }

        for (int timestep = 0; timestep < max_step; timestep++)
        {
            // Memops
            // ............................
            CUdeviceptr dptr;
            volatile int* hptr;
            AMREX_CUDA_SAFE_CALL(cudaHostAlloc((void**) &hptr, sizeof(int)*max_streams,
                                                cudaHostAllocMapped));
            for (int i=0; i<max_streams; ++i) {
                *(hptr+i) = 0;
            }

            CU_CHECK(cuMemHostGetDevicePointer(&dptr, (void*) hptr, 0));

            amrex::Print() << "======================================" << std::endl;
            amrex::Print() << "Starting memops " << timestep
                           << " at " << amrex::second() - time_zero
                           << " with sleep of " << sleep_ns << std::endl;

            // Needs to do at least one kernel before the first wait?
            amrex::single_task(streams[0],
            [=] AMREX_GPU_DEVICE () {
                AMREX_DEVICE_PRINTF("Starting Sync Kernel 1\n");
                __nanosleep(sleep_ns);
                AMREX_DEVICE_PRINTF("Ending Sync Kernel 1\n");
            });
            amrex::Gpu::synchronize();

            CU_CHECK(cuStreamWaitValue32_v2(streams[3], dptr,                 1, CU_STREAM_WAIT_VALUE_EQ));
            CU_CHECK(cuStreamWaitValue32_v2(streams[3], dptr+(1*sizeof(int)), 1, CU_STREAM_WAIT_VALUE_EQ));
            CU_CHECK(cuStreamWaitValue32_v2(streams[3], dptr+(2*sizeof(int)), 1, CU_STREAM_WAIT_VALUE_EQ));

            amrex::single_task(streams[3],
            [=] AMREX_GPU_DEVICE () {
                AMREX_DEVICE_PRINTF("Starting Sync Kernel D\n");
                __nanosleep(sleep_ns);
                AMREX_DEVICE_PRINTF("Ending Sync Kernel D\n");
            });

            amrex::single_task(streams[0],
            [=] AMREX_GPU_DEVICE () {
                AMREX_DEVICE_PRINTF("Starting Sync Kernel A\n");
                __nanosleep(sleep_ns);
                AMREX_DEVICE_PRINTF("Ending Sync Kernel A\n");
            });

            amrex::single_task(streams[1],
            [=] AMREX_GPU_DEVICE () {
                AMREX_DEVICE_PRINTF("Starting Sync Kernel B\n");
                __nanosleep(sleep_ns);
                AMREX_DEVICE_PRINTF("Ending Sync Kernel B\n");
            });

            amrex::single_task(streams[2],
            [=] AMREX_GPU_DEVICE () {
                AMREX_DEVICE_PRINTF("Starting Sync Kernel C\n");
                __nanosleep(sleep_ns);
                AMREX_DEVICE_PRINTF("Ending Sync Kernel C\n");
            });

            CU_CHECK(cuStreamWriteValue32_v2(streams[0], dptr,                 1, CU_STREAM_WRITE_VALUE_DEFAULT));
            CU_CHECK(cuStreamWriteValue32_v2(streams[1], dptr+(1*sizeof(int)), 1, CU_STREAM_WRITE_VALUE_DEFAULT));
            CU_CHECK(cuStreamWriteValue32_v2(streams[2], dptr+(2*sizeof(int)), 1, CU_STREAM_WRITE_VALUE_DEFAULT));

            do_step(sleep_host, time_zero);

            amrex::Gpu::synchronize();
            amrex::Print() << "Finishing memops on " << timestep
                           << " at " << amrex::second() - time_zero << std::endl;

            AMREX_CUDA_SAFE_CALL(cudaFreeHost((void*) hptr));
        }

        amrex::Print() << "======================================" << std::endl;
    }
    amrex::Finalize();
}
