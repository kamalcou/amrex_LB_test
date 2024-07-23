#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <chrono>
#include <cstring>

#include <omp.h>

#include <iomanip>
#include <limits>

//#include "mpi.h"
using namespace std;
bool array_true=false;


double max_val(double* A, int i, int j)
{
    double max_val = A[0];

    //#pragma omp parallel for reduction(max:max_val) 
    for (int idx = i; idx < j; idx++){
        max_val = max_val > A[idx] ? max_val : A[idx];
        //*position=idx;
    }
       

    return max_val; 
}


double get_maxt(int *combo, int *maxt_comb, double *guess, int N,int nr) {
    double maxg[nr]={0};
    double maxt=0;
    // int thread_rank = omp_get_thread_num();
    
    for (int r=0;r<nr;r++){ // for every bucket
    //    #pragma omp parallel for
        for (int i=0;i<N;i++) { //for every element
            if(combo[i]==r){
                maxg[r]+=guess[i]; // this guess is on bucket r so add to the sum
                // cout<<"Guess: "<<fixed<<guess[i]<<fixed<<" maxg["<<r<<"]="<<maxg[r]<<endl;
                // if(thread_rank==0)
                //     amrex::Print()<<"maxg[r]="<<maxg[r]<<" i= "<<i<<" , "<<" guess: "<<guess[i]<<" , ";
            }
             
        }
        
        //#pragma omp critical
        if (maxg[r]>maxt){
            maxt=maxg[r];
            for (int i=0;i<N;i++){
                maxt_comb[i]=combo[i];
            }
            
        }
        
    }
    //  amrex::Print()<<std::endl;
    // cout<<"maxt= "<<fixed<<maxt<<endl;
    return maxt;
}

int* ternary(long int n, int nr,int N) {
    int * nums = new int[N];
    for(int i=0;i<N;i++) nums[i]=0;
    int L=N;

    while (n){
        auto dv= std::div(n,(long int)(nr));
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
    

void get_all_combos(int N, int nr, double *guess, int *ranks){

    

    unsigned long long int nmin=0;
    unsigned long long int nmax=double(pow(nr,(N))/2.);//8
    cout<<" nr= "<<nr<< " items= "<<N/nr<<" nmax= "<<nmax<<endl;
    
    double local_max=0,global_max=0;
    unsigned int position;
    unsigned long int i;
    int j;
    
    // cout<<"get_all_combos function guess:"<<endl;
    // for (int i=0;i<N;i++){
    //         cout<<guess[i]<<" ";
    //     }
    // cout<<endl;
    
     #pragma omp parallel default(none) shared(N,nr,nmax,global_max,guess,cout,position) private(i,j,local_max) 
       {
           
        //    if(thread_rank==0)
        //     amrex::Print()<< "Total number of threads: "<<num_threads<<std::endl;
      
       int num_threads=omp_get_num_threads(); 
       int rank = omp_get_thread_num();  
       
       unsigned long int chunk_size=nmax/num_threads;
       unsigned long int start=rank*chunk_size;
       unsigned long int end=start+chunk_size;
      
       // cout<<"Rank: "<<rank<<" start: "<<start<<" end: "<<end<<endl;

        

        for( i=start;i<end;i++){   // for rank 0, i=0 
            int * combo = new int[N+1];
            int * maxt_comb=new int[N+1];
            // int thread_rank = omp_get_thread_num(); 
            //double * guess2=new double[N+1]; 

            
            
            for (j=0;j<N+1;j++){
                combo[j] = 0;
                maxt_comb[j]=0;
                // guess2[i]=guess[i];
            }
            // amrex::Print()<<__LINE__<<endl;
            //check there is more than one bucket
            if (nr!=1){
                // #pragma omp parallel
                combo=ternary(i,nr,N);    // it will work with combinations of bucket picks, which bucket pick what.
                
                if (combo[0]==-1) {	    
                    cout<<"Nmax too large"<<endl;
                    exit(0);
                }
            }
            
            double maxt=get_maxt(combo,maxt_comb,guess,N,nr);
            if(local_max<maxt)
                {
                    local_max=maxt;
                    
                }
            // cout<<"rank: "<<rank<<fixed<<" local_max: "<<local_max<<endl;           
            // #pragma openmp barrier


            #pragma omp reduction( < : global_max)
           //critical 
            {
                if(global_max<local_max){
                    global_max=local_max;
                    position=i;
                }
            
            }
           
            
        }
         if(rank==0)
            {    cout<<"number of threads: "<<num_threads<<endl;
                cout<<"rank: "<<rank<<fixed<<" global_max: "<<local_max<<endl;
            }
            
       }
    //    #pragma omp parallel for reduction(max:global_maxima) 
    // for (int idx = i; idx < j; idx++)
    //    max_val = max_val > A[idx] ? max_val : A[idx];
    //    #pragma parallel critical
    //    #pragma omp parallel for reduction(max:global_maxima)
    // int part=1;
    //    for(long int i=nmin;i<nmax;i++){
    //        if (maxElements[i] > global_maxima) {
    //             global_maxima = maxElements[i];
    //             position=i;
    //         }
    //    }
    // Convert std::vector<double> to double*
//     double* data_ptr = maxElements.data();
//     int *posi;
//    global_maxima= max_val(data_ptr,nmin,nmax);
    // int * final_combo = new int[N+1];
    // final_combo=ternary(position,nr,N);
    // print here maxt  and i for combination
    // cout<<"global maxima: "<<fixed<<global_maxima<<" position= "<<position<<endl;
    // for(int i=0; i<N;i++)
    //     cout<<final_combo[i]<<" ";
    // cout<<endl;
    // // amrex::Print()<<std::endl;
    // basechange_fill(N, nr,guess,ranks);
    
    return;
    }

void BruteForceDoIt(int nbins, int nitems, double mean, double stdev,double *guess){

    // BL_PROFILE("BruteForceDoIt()");
    int N=nbins*nitems;
    // int N=nitems;
    int nr=nbins;
    int ranks [N];

    

    for (int i = 0; i<nr;i++){
        ranks[i]=i;
       // myfile << ranks[i] << " ";   // write list of buckets 
    }
    
    // amrex::Print()<<__LINE__<<endl;
     get_all_combos(N,nr,guess,ranks);


}




int main( int argc, char* argv[]) {


    auto start_time = std::chrono::high_resolution_clock::now();

    
    
    int nbins=atoi(argv[1]);
    int nitems=atoi(argv[2]);
    // int nr=atoi(argv[1]); //nr= number of bucket
    // int N=atoi(argv[2])*nr; //b
    int N=nitems*nbins;
    // int N=nitems;
    double guess [N];
    int ranks [N];

    
    double mean = 100000;  /// We need to have read from file
    double stdev = 4523;
    //generate array of guesses with normal distribution
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(mean,stdev);
    // myfile.open(guess_fn);
    for (int i=0;i<N;i++){
        guess[i]=distribution(generator);  //guess value based on the normal distribution
	if (guess[i]<0){
	    cout<<"negative guess, make mean higher or standard devation smaller"<<endl;
            exit(0);
	   }
	
    }
//     cout<<"main function guess:"<<endl;
//     for (int i=0;i<N;i++){
//         cout<<guess[i]<<" ";
//     }
//    cout<<endl;
   BruteForceDoIt(nbins, nitems,mean, stdev,guess);
    // get_all_combos(N,nr,guess,ranks);  // N=total number of boxes, nr= number of buckets 
                                                //guess=based on normal distribution 
                                                //ranks= collection of ranks number suppose 0-63 for 64 ranks

    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    cout << "Time taken: " << elapsed_time.count() << " milliseconds" << endl;

    return 0;
}

