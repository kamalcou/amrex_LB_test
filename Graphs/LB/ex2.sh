#!/bin/bash


# export OMP_NUM_THREADS=256
# ./bf 2 2 >> output_256_nitems.txt
# ./bf 2 3 >> output_256_nitems.txt
# ./bf 2 4 >> output_256_nitems.txt
# ./bf 2 5 >> output_256_nitems.txt
# ./bf 2 6 >> output_256_nitems.txt
# ./bf 2 7 >> output_256_nitems.txt
# ./bf 2 8 >> output_256_nitems.txt
# ./bf 2 9 >> output_256_nitems.txt
# ./bf 2 10 >> output_256_nitems.txt
# ./bf 2 11 >> output_256_nitems.txt
# ./bf 2 12 >> output_256_nitems.txt
# ./bf 2 13 >> output_256_nitems.txt
# ./bf 2 14 >> output_256_nitems.txt
# ./bf 2 15 >> output_128_nitems.txt

CC bf.cpp -o bf -fopenmp

# export OMP_NUM_THREADS=1
# ./bf 2 14 >> output_2_14_reduction3_after_barrier.txt
# export OMP_NUM_THREADS=2
# ./bf 2 14 >> output_2_14_reduction3_after_barrier.txt
# export OMP_NUM_THREADS=4
# ./bf 2 14 >> output_2_14_reduction3_after_barrier.txt
# export OMP_NUM_THREADS=8
# ./bf 2 14 >> output_2_14_reduction3_after_barrier.txt
# export OMP_NUM_THREADS=16
# ./bf 2 14 >> output_2_14_reduction3_after_barrier.txt
# export OMP_NUM_THREADS=32
# ./bf 2 14 >> output_2_14_reduction3_after_barrier.txt
# export OMP_NUM_THREADS=64
# ./bf 2 14 >> output_2_14_reduction3_after_barrier.txt
# export OMP_NUM_THREADS=128
# ./bf 2 14 >> output_2_14_reduction3_after_barrier.txt
# export OMP_NUM_THREADS=256
# ./bf 2 14 >> output_2_14_reduction3_after_barrier.txt

export OMP_NUM_THREADS=1

./bf 2 8 >> output7.$OMP_NUM_THREADS.txt
./bf 2 9 >> output7.$OMP_NUM_THREADS.txt
./bf 2 10 >> output7.$OMP_NUM_THREADS.txt
./bf 2 11 >> output7.$OMP_NUM_THREADS.txt
./bf 2 12 >> output7.$OMP_NUM_THREADS.txt
./bf 2 13 >> output7.$OMP_NUM_THREADS.txt
./bf 2 14 >> output7.$OMP_NUM_THREADS.txt

export OMP_NUM_THREADS=2

./bf 2 8 >> output7.$OMP_NUM_THREADS.txt
./bf 2 9 >> output7.$OMP_NUM_THREADS.txt
./bf 2 10 >> output7.$OMP_NUM_THREADS.txt
./bf 2 11 >> output7.$OMP_NUM_THREADS.txt
./bf 2 12 >> output7.$OMP_NUM_THREADS.txt
./bf 2 13 >> output7.$OMP_NUM_THREADS.txt
./bf 2 14 >> output7.$OMP_NUM_THREADS.txt
export OMP_NUM_THREADS=4

./bf 2 8 >> output7.$OMP_NUM_THREADS.txt
./bf 2 9 >> output7.$OMP_NUM_THREADS.txt
./bf 2 10 >> output7.$OMP_NUM_THREADS.txt
./bf 2 11 >> output7.$OMP_NUM_THREADS.txt
./bf 2 12 >> output7.$OMP_NUM_THREADS.txt
./bf 2 13 >> output7.$OMP_NUM_THREADS.txt
./bf 2 14 >> output7.$OMP_NUM_THREADS.txt



export OMP_NUM_THREADS=8

./bf 2 8 >> output7.$OMP_NUM_THREADS.txt
./bf 2 9 >> output7.$OMP_NUM_THREADS.txt
./bf 2 10 >> output7.$OMP_NUM_THREADS.txt
./bf 2 11 >> output7.$OMP_NUM_THREADS.txt
./bf 2 12 >> output7.$OMP_NUM_THREADS.txt
./bf 2 13 >> output7.$OMP_NUM_THREADS.txt
./bf 2 14 >> output7.$OMP_NUM_THREADS.txt


export OMP_NUM_THREADS=16

./bf 2 8 >> output7.$OMP_NUM_THREADS.txt
./bf 2 9 >> output7.$OMP_NUM_THREADS.txt
./bf 2 10 >> output7.$OMP_NUM_THREADS.txt
./bf 2 11 >> output7.$OMP_NUM_THREADS.txt
./bf 2 12 >> output7.$OMP_NUM_THREADS.txt
./bf 2 13 >> output7.$OMP_NUM_THREADS.txt
./bf 2 14 >> output7.$OMP_NUM_THREADS.txt

export OMP_NUM_THREADS=32

./bf 2 8 >> output7.$OMP_NUM_THREADS.txt
./bf 2 9 >> output7.$OMP_NUM_THREADS.txt
./bf 2 10 >> output7.$OMP_NUM_THREADS.txt
./bf 2 11 >> output7.$OMP_NUM_THREADS.txt
./bf 2 12 >> output7.$OMP_NUM_THREADS.txt
./bf 2 13 >> output7.$OMP_NUM_THREADS.txt
./bf 2 14 >> output7.$OMP_NUM_THREADS.txt


export OMP_NUM_THREADS=64

./bf 2 8 >> output7.$OMP_NUM_THREADS.txt
./bf 2 9 >> output7.$OMP_NUM_THREADS.txt
./bf 2 10 >> output7.$OMP_NUM_THREADS.txt
./bf 2 11 >> output7.$OMP_NUM_THREADS.txt
./bf 2 12 >> output7.$OMP_NUM_THREADS.txt
./bf 2 13 >> output7.$OMP_NUM_THREADS.txt
./bf 2 14 >> output7.$OMP_NUM_THREADS.txt


export OMP_NUM_THREADS=128

./bf 2 8 >> output7.$OMP_NUM_THREADS.txt
./bf 2 9 >> output7.$OMP_NUM_THREADS.txt
./bf 2 10 >> output7.$OMP_NUM_THREADS.txt
./bf 2 11 >> output7.$OMP_NUM_THREADS.txt
./bf 2 12 >> output7.$OMP_NUM_THREADS.txt
./bf 2 13 >> output7.$OMP_NUM_THREADS.txt
./bf 2 14 >> output7.$OMP_NUM_THREADS.txt


export OMP_NUM_THREADS=256

./bf 2 8 >> output7.$OMP_NUM_THREADS.txt
./bf 2 9 >> output7.$OMP_NUM_THREADS.txt
./bf 2 10 >> output7.$OMP_NUM_THREADS.txt
./bf 2 11 >> output7.$OMP_NUM_THREADS.txt
./bf 2 12 >> output7.$OMP_NUM_THREADS.txt
./bf 2 13 >> output7.$OMP_NUM_THREADS.txt
./bf 2 14 >> output7.$OMP_NUM_THREADS.txt


