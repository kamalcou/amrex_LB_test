// A DP based CPP program for painter's partition problem 
#include <climits> 
#include <iostream> 
#include <vector>
using namespace std; 

// function to calculate sum between two indices 
// in array 
long  sum(vector<long> arr, int from, int to);

// bottom up tabular dp 
long  findMax(vector<long> arr, int n, int k); 
bool isPartitionPossible(vector<long> arr, int n, int k, long maxTime);
long minTime(vector<long> arr, int n, int k);
// driver function 
vector< vector<int> > painterPartition(vector<long> arr,int k);