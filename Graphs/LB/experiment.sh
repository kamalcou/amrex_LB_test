#!/bin/bash         

echo "Hello, GeeksforGeeks"
for ((nbins=2;nbins<=100;nbins=nbins*2))
do

    # nbins=2
    d_size=256
    boxes=8
    for ((i=128; i>=16; i=i/2))
    do
        for ((j=i;  j>=16; j=j/2))
        do
            for((k=j; k>=16; k=k/2))
            do
                echo "Number: $i,$j,$k"
                boxes=$(($((d_size/i))*$((d_size/j))*$((d_size/k))))
                echo "boxes=$boxes"
                cmd='./main3d.gnu.x86-milan.TPROF.ex inputs  nbins='$nbins' max_grid_size="('$i,$j,$k')" >output/'$nbins'_'$boxes'_output.txt'
                echo $cmd
                eval $cmd
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