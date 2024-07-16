#!/bin/bash
for ((i=1;i<=10;i=i*2))
do
#   echo "Welcome $i times"
#   j=$((i+2))
#   echo "Welcome $j times"
  export OMP_NUM_THREADS=$((i))
  echo $((OMP_NUM_THREADS))
done