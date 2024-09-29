// A DP based CPP program for painter's partition problem 
#include <climits> 
#include <iostream> 
#include <vector>
using namespace std; 

// function to calculate sum between two indices 
// in array 
long  sum(vector<long> arr, int from, int to) 
{ 
	long int total = 0; 
	for (int i = from; i <= to; i++) 
		total += arr[i]; 
	
	return total; 
} 

// bottom up tabular dp 
long  findMax(vector<long> arr, int n, int k) 
{ 
	// initialize table 
	long int dp[k + 1][n + 1] = { 0 }; 

	// base cases 
	// k=1 
	for (int i = 1; i <= n; i++) 
		dp[1][i] = sum(arr, 0, i - 1); 

	// n=1 
	for (int i = 1; i <= k; i++) 
		dp[i][1] = arr[0]; 

	// 2 to k partitions 
	for (int i = 2; i <= k; i++) { // 2 to n boards 
		for (int j = 2; j <= n; j++) { 

			// track minimum 
			long  best = LONG_MAX; 
			

			// i-1 th separator before position arr[p=1..j] 
			for (int p = 1; p <= j; p++) 
				best = min(best, max(dp[i - 1][p], 
							sum(arr, p, j - 1)));	 

			dp[i][j] = best; 
		} 
	} 
	
	 
	return dp[k][n]; 
} 

bool isPartitionPossible(int arr[], int n, int k, long long maxTime){
        
        long long currTime=0, worker=1;
        for(int i=0;i<n;i++)
        {
            if(currTime+arr[i]>maxTime){
                worker++;
                
                if(worker>k) return false;
                currTime=arr[i];
            }
            else currTime+=arr[i];
        }
        return true;
        
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long sum=0,max=arr[0];
       // if(k>n) return -1;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(max<arr[i]){
                max=arr[i];
            }
        }
        long long h=sum,l=max,mid,res;
        while(l<=h){
            mid=l+(h-l)/2;
            if(isPartitionPossible(arr,n,k,mid)){
                res=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return res;
        
    }

// driver function 
int  main() 
{ 
	long  a[] = {909990672,1000000001,944067182,869552438,969416923,836439888,970584008,934893898 }; 
	 //long int arr[] = { 90,10,94,86,96,83,97,93 }; 
	//long long a[] = { 10, 20, 60, 50, 30, 40 };
	//long int a[] = { 10, 40, 20, 30, 40, 50 };
	int n = sizeof(a) / sizeof(a[0]); 
	vector<long> arr;
	arr.assign(a,a+n);

	// long int n=arr.size();
	
	
	int k;
	//int k = 2; 
	long maxVal=findMax(arr,n,k);
	cout << maxVal << endl; 
	vector< vector<int> > vec(k);
	vector< vector<int> > vec1(k);
	int index;
	
	for(int i=0,j=i, p=0;p<k && j<n;p++){
		
		long val=sum(arr,i,j);
		while(maxVal>val && j<n){
			j++;
			val=sum(arr,i,j);
		}
		cout<<"i= "<<i<<" j= "<<j<<endl;
		if(maxVal==val){
			for(int a=i;a<=j;a++){
				cout<<"a="<<a<<endl;
				index=a;
				cout<<"arr[a]="<<arr[a]<<endl;
				
				//vec[p][0]=a;
				vec[p].push_back(index);
				// vec1[p].push_back(a);
			}
			j++;
			i=j;
			
		}
		else{
			for(int a=i;a<j;a++){
				cout<<"a="<<a<<endl;
				cout<<"arr[a]="<<arr[a]<<endl;
				index=a;
				vec[p].push_back(index);
			}
			i=j;
			

		}

	}
	for(int i=0;i<k;i++){
        for(int j=0;j<vec[i].size();j++){
			cout<<"vec["<<i<<"]["<<j<<"]="<<vec[i][j]<<endl;
		}
		cout<<endl;
	}
	//return vec;
	return 0;
} 