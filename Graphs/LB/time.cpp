#include <stdio.h>
#include <sys/time.h>
#include<omp.h>
#include <cstdlib>

int* ternary( int n, int nr,int N) {
    int * nums = new int[N];
    for(int i=0;i<N;i++) nums[i]=0;
    int L=N;

    while (n){
        auto dv= std::div(n,(int)(nr));
        n = dv.quot;
	    int r = dv.rem;
        if (L==0){
                nums[0]=-1;
            break;
        }
        L--;
        nums[L]=r;
        }
        return nums;
}
int main (int argc, char** argv) {
    struct timeval tvalBefore, tvalAfter;  // removed comma

    
    int i =0;
    int N=1000000;
    #pragma omp parallel default(none) shared(N) private(i,tvalBefore, tvalAfter)
    {
        int rank = omp_get_thread_num();  
        int num_threads=omp_get_num_threads(); 
        if(rank==0){
            gettimeofday (&tvalBefore, NULL);
        }
        int chunk_size=N/num_threads;
        int start=rank*chunk_size;
        int end=start+chunk_size;
        for ( i=start;i < end;i++) {
                int * n=ternary(i,2,16);
            }

    
    
        if(rank==0 ){
            gettimeofday (&tvalAfter, NULL);
            printf("Time in microseconds: %ld microseconds\n",
                ((tvalAfter.tv_sec - tvalBefore.tv_sec)*1000000L
            +tvalAfter.tv_usec) - tvalBefore.tv_usec
            ); // Added semicolon
        }
    
    }

    // Changed format to long int (%ld), changed time calculation

   
    return 0;
}