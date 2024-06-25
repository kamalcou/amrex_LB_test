#!/bin/bash

echo "Hello, GeeksforGeeks"
for ((domain_size=256;domain_size<=256;domain_size=domain_size*2))
    do
    for ((nbins=2;nbins<=6000;nbins=nbins*2))
    do

        # nbins=2
        # domain_size=256
        max_grid_size=$((domain_size/nbins))
        grid_size=$((max_grid_size/2))
        
        # boxes=8
        for ((i=max_grid_size; i>=grid_size && grid_size > 0; i=i/2))
        do
            for ((j=i;  j>=grid_size; j=j/2))
            do
                for((k=j; k>=grid_size; k=k/2))
                do
                    echo "i=$i,j=$j,k=$k"
                    boxes=$(($((domain_size/i))*$((domain_size/j))*$((domain_size/k))))
                    echo "nbins=$nbins"
                    echo "boxes=$boxes"
                    echo "max_grid_size=$max_grid_size"
                    echo  "grid_size=$grid_size"
                    cmd='./main3d.gnu.x86-milan.TPROF.ex inputs  nbins='$nbins' domain="('$domain_size,$domain_size,$domain_size')" max_grid_size="('$i,$j,$k')" >output/'$domain_size'_'$nbins'_'$boxes'_output.txt'
                    echo $cmd
                    eval $cmd
                done
                
            done
        done
    done
done
# ./main3d.gnu.x86-milan.TPROF.ex inputs  nbins=2 max_grid_size="(128,128,128)" >output/2_8_output.txt
# ./main3d.gnu.x86-milan.TPROF.ex inputs  nbins=2 max_grid_size="(128,128,64)" >output/2_16_output.txt
# ./main3d.gnu.x86-milan.TPROF.ex inputs  nbins=2 max_grid_size="(128,64,64)" >output/2_32_output.txt
# ./main3d.gnu.x86-milan.TPROF.ex inputs  nbins=2 max_grid_size="(64,64,64)" >output/2_64_output.txt
# ./main3d.gnu.x86-milan.TPROF.ex inputs  nbins=2 max_grid_size="(64,64,32)" >output/2_128_output.txt
# ./main3d.gnu.x86-milan.TPROF.ex inputs  nbins=2 max_grid_size="(64,32,32)" >output/2_256_output.txt
# ./main3d.gnu.x86-milan.TPROF.ex inputs  nbins=2 max_grid_size="(32,32,32)" >output/2_512_output.txt
# ./main3d.gnu.x86-milan.TPROF.ex inputs  nbins=2 max_grid_size="(32,32,16)" >output/2_1024_output.txt
# ./main3d.gnu.x86-milan.TPROF.ex inputs  nbins=2 max_grid_size="(32,16,16)" >output/2_2048_output.txt
# ./main3d.gnu.x86-milan.TPROF.ex inputs  nbins=2 max_grid_size="(16,16,16)" >output/2_4096_output.txt