#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <chrono>
#include <cstring>
//#include "mpi.h"
using namespace std;
//bool array_true=false;

char* getfn(int it, char* b, char* c, char* d);

double get_maxt(int *combo, double *guess, int N,int nr);

void BruteForceDoIt(int nbins, int nitems, double mean, double stdev,double *guess);

int* ternary(int n, int nr,int N);
    
void basechange_fill(int N, int nr,double *guess, int *ranks);


void get_all_combos(int N, int nr, double *guess, int *ranks);
