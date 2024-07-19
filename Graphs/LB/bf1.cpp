#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <chrono>
#include <cstring>

#include <omp.h>

#include <iomanip>
#include <limits>

#include <unistd.h>

//#include "mpi.h"
using namespace std;




    
void compute_serial(int N){
    auto start_time = std::chrono::high_resolution_clock::now();
    int sum=0;
    for(int i=0;i<N;i++){

            sleep(1);
            sum+=i;
            // cout<<"."<<endl;
            // cout<<i<<endl;
        }
    cout<<sum<<endl;
    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    cout << "Time taken: " << elapsed_time.count() << " milliseconds" << endl;

}
void compute(int N){
    auto start_time = std::chrono::high_resolution_clock::now();
    
    int threads;
    int partition;
    int sum=0;
    int local_sum;
    int local_max=0;
    int global_max=0;

    
    int i;
    #pragma omp parallel default(none) shared(partition,cout,N,threads,sum,global_max) private(i,local_sum,local_max) 
    {   
        threads=omp_get_num_threads();
        cout<<"threads: "<<threads<<endl;
        partition=N/threads;
       
        int ranks = omp_get_thread_num();
        
        int start=ranks*partition;
        int end=start+(partition);
        cout<<"ranks= "<<ranks<<" of "<<threads<<" start: "<<start<<" end: "<<end<<endl;
        local_sum=0;
        for( i=start;i<end;i++){

                sleep(1);
                // if()
                local_sum+=i;
                if(i>local_max){
                    local_max=i;
                }
                // cout<<"."<<endl;
                // cout<<i<<endl;
            }
        cout<<"ranks: "<<ranks<<" local sum: "<<local_sum<<endl;
        #pragma omp citical
        { 
            sum += local_sum;
            if(local_max>global_max){
                global_max=local_max;
            }
        }



    }
    cout<<"sum: : "<<sum<<" global max: "<<global_max<<endl;
    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    cout << "Time taken: " << elapsed_time.count() << " milliseconds" << endl;

}






int main( int argc, char* argv[]) {


    

    
    
    int nbins=atoi(argv[1]);
    int nitems=atoi(argv[2]);
    // int nr=atoi(argv[1]); //nr= number of bucket
    // int N=atoi(argv[2])*nr; //b
    int N=nitems*nbins;
    
    compute_serial(N);

    compute(N);


    

    return 0;
}

