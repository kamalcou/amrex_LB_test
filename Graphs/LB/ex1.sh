#!/bin/bash
#SBATCH -N 1
#SBATCH -C cpu
#SBATCH -q debug
#SBATCH -J loadBalancing
#SBATCH -t 00:05:00
#SBATCH -o %x_%j.out
#SBATCH -e %x_%j.err

#OpenMP settings:
export OMP_NUM_THREADS=4
export OMP_PLACES=threads
export OMP_PROC_BIND=spread

#run the application:
# srun -n 1  --cpu_bind=cores ./main3d.gnu.x86-milan.TPROF.OMP.ex inputs >& output3.txt 
# srun -n 1 -c 256 --cpu_bind=cores experiment.sh >& out_256_.$OMP_NUM_THREADS.txt


# srun -n 1 -c 256 --cpu_bind=cores experiment.sh >& out_1_.$OMP_NUM_THREADS.txt
CC bf.cpp -o bf -fopenmp


# for ((i=1;i<=256;i=i*2))
# do

    # export OMP_NUM_THREADS=$((i))
    # echo $i
    

    # ./bf 2 2 >> output.$OMP_NUM_THREADS.txt
    # ./bf 2 3 >> output.$OMP_NUM_THREADS.txt
    # ./bf 2 4 >> output.$OMP_NUM_THREADS.txt
    # ./bf 2 5 >> output.$OMP_NUM_THREADS.txt
    # ./bf 2 6 >> output.$OMP_NUM_THREADS.txt
    # ./bf 2 7 >> output.$OMP_NUM_THREADS.txt
    # ./bf 2 8 >> output.$OMP_NUM_THREADS.txt
    # ./bf 2 9 >> output.$OMP_NUM_THREADS.txt
    # ./bf 2 10 >> output.$OMP_NUM_THREADS.txt
    # ./bf 2 11 >> output.$OMP_NUM_THREADS.txt
    # ./bf 2 12 >> output.$OMP_NUM_THREADS.txt
    # ./bf 2 13 >> output.$OMP_NUM_THREADS.txt
    # ./bf 2 14 >> output.$OMP_NUM_THREADS.txt
    # ./bf 2 15 >> output.$OMP_NUM_THREADS.txt
    export OMP_NUM_THREADS=1
    echo "########################"
    ./bf 2 2 >> output.$OMP_NUM_THREADS.txt
    ./bf 3 2 >> output.$OMP_NUM_THREADS.txt
    ./bf 4 2 >> output.$OMP_NUM_THREADS.txt
    ./bf 5 2 >> output.$OMP_NUM_THREADS.txt
    ./bf 6 2 >> output.$OMP_NUM_THREADS.txt
    ./bf 7 2 >> output.$OMP_NUM_THREADS.txt
    ./bf 9 2 >> output.$OMP_NUM_THREADS.txt
    ./bf 10 2 >> output.$OMP_NUM_THREADS.txt
    ./bf 11 2 >> output.$OMP_NUM_THREADS.txt
    ./bf 12 2 >> output.$OMP_NUM_THREADS.txt
    ./bf 13 2 >> output.$OMP_NUM_THREADS.txt
    ./bf 14 2 >> output.$OMP_NUM_THREADS.txt
    ./bf 15 2 >> output.$OMP_NUM_THREADS.txt

    echo "-----------------------"
# done
