#!/bin/bash

# echo "Hello, GeeksforGeeks"
# nbins=2
# for ((domain_size_x=256;domain_size_x<=256;domain_size_x=domain_size_x*2))
#     do
#     for ((domain_size_y=256;domain_size_y<=256;domain_size_y=domain_size_y*2))
#         do
#         for ((domain_size_z=256;domain_size_z<=256;domain_size_z=domain_size_z*2))
#             do
#             # for ((nbins=2;nbins<=64;nbins=nbins*2))
#             #     do

#                 nbins=2
#                 # domain_size=256
#                 max_grid_size=$((domain_size_x/nbins))
#                 grid_size=$((max_grid_size/2))
                
#                 # boxes=8
#                 for ((i=max_grid_size; grid_size > 0; i=i/2))
#                 do
#                     for ((j=i; grid_size > 0; j=j/2))
#                     do
#                         for((k=j; grid_size > 0; k=k/2))
#                         do
#                             echo "i=$i,j=$j,k=$k"
#                             boxes=$(($((domain_size_x/i))*$((domain_size_y/j))*$((domain_size_z/k))))
#                             boxes=$((boxes/nbins))
                            
#                             if [ $boxes -gt 16 ]
#                             then
#                                 grid_size=0
#                                 nbins=$((nbins*2))
#                                 echo "------nbins=$nbins"

#                                 max_grid_size=$((domain_size_x/nbins))
#                                 break
                               
#                             fi
#                             echo "nbins=$nbins"
#                             echo "boxes=$boxes"
#                             echo "max_grid_size=$max_grid_size"
#                             # echo  "grid_size=$grid_size"
#                             cmd='./main3d.gnu.x86-milan.TPROF.ex inputs  nbins='$nbins' domain="('$domain_size_x,$domain_size_y,$domain_size_z')" max_grid_size="('$i,$j,$k')" >output/'$nbins'_'$boxes'_domain_size=('$domain_size_x','$domain_size_y','$domain_size_z') max_grid_size=('$i','$j','$k')__output.txt'
#                             echo $cmd
#                             # eval $cmd
#                         done
                        
#                     done
#                 done
#             # done
#         done
#     done
# done
# ./main3d.gnu.x86-milan.TPROF.OMP.ex inputs 
# ./main3d.gnu.x86-milan.TPROF.ex inputs  nbins=2 max_grid_size="(128,128,128)" >output/2_8_output.txt
# ./main3d.gnu.x86-milan.TPROF.ex inputs  nbins=2 max_grid_size="(128,128,64)" >output/2_16_output_.$SLURM_JOBID.txt
# # ./main3d.gnu.x86-milan.TPROF.ex inputs  nbins=2 max_grid_size="(128,64,64)" >output/2_32_output.txt
# ./main3d.gnu.x86-milan.TPROF.ex inputs  nbins=2 max_grid_size="(64,64,64)" >output/2_64_output_.$SLURM_JOBID.txt
# # ./main3d.gnu.x86-milan.TPROF.ex inputs  nbins=2 max_grid_size="(64,64,32)" >output/2_128_output.txt
# # ./main3d.gnu.x86-milan.TPROF.ex inputs  nbins=2 max_grid_size="(64,32,32)" >output/2_256_output.txt
# # ./main3d.gnu.x86-milan.TPROF.ex inputs  nbins=2 max_grid_size="(32,32,32)" >output/2_512_output.txt
# # ./main3d.gnu.x86-milan.TPROF.ex inputs  nbins=2 max_grid_size="(32,32,16)" >output/2_1024_output.txt
# # ./main3d.gnu.x86-milan.TPROF.ex inputs  nbins=2 max_grid_size="(32,16,16)" >output/2_2048_output.txt
# #  ./main3d.gnu.x86-milan.TPROF.OMP.ex inputs  nbins=2 max_grid_size="(16,16,16)" >output/2_4096_output.txt

# ./main3d.gnu.x86-milan.TPROF.ex inputs  nbins=128 max_grid_size="(128,128,64)"

# nbins=2-128
#boxes= 4-16

#domain=256
#max_grid_size=


./main3d.gnu.x86-milan.TPROF.ex inputs nbins=2 domain="(256,256,256)" max_grid_size="(128,128,128)" >output/2_4_output.txt
./main3d.gnu.x86-milan.TPROF.ex inputs nbins=2 domain="(256,256,256)" max_grid_size="(128,128,64)" >output/2_8_output.txt
./main3d.gnu.x86-milan.TPROF.ex inputs nbins=2 domain="(256,256,256)" max_grid_size="(128,64,64)" >output/2_16_output.txt
./main3d.gnu.x86-milan.TPROF.ex inputs nbins=4 domain="(256,256,256)" max_grid_size="(128,128,64)" >output/4_4_output.txt
./main3d.gnu.x86-milan.TPROF.ex inputs nbins=4 domain="(256,256,256)" max_grid_size="(128,64,64)" >output/4_8_output.txt
./main3d.gnu.x86-milan.TPROF.ex inputs nbins=4 domain="(256,256,256)" max_grid_size="(64,64,64)" >output/4_16_output.txt
./main3d.gnu.x86-milan.TPROF.ex inputs nbins=8 domain="(256,256,256)" max_grid_size="(64,64,64)" >output/8_4_output.txt
./main3d.gnu.x86-milan.TPROF.ex inputs nbins=8 domain="(256,256,256)" max_grid_size="(64,64,32)" >output/8_8_output.txt
./main3d.gnu.x86-milan.TPROF.ex inputs nbins=8 domain="(256,256,256)" max_grid_size="(64,32,32)" >output/8_16_output.txt
./main3d.gnu.x86-milan.TPROF.ex inputs nbins=16 domain="(256,256,256)" max_grid_size="(64,64,32)" >output/16_4_output.txt
./main3d.gnu.x86-milan.TPROF.ex inputs nbins=16 domain="(256,256,256)" max_grid_size="(64,32,32)" >output/16_8_output.txt
./main3d.gnu.x86-milan.TPROF.ex inputs nbins=16 domain="(256,256,256)" max_grid_size="(32,32,32)" >output/16_16_output.txt
./main3d.gnu.x86-milan.TPROF.ex inputs nbins=32 domain="(256,256,256)" max_grid_size="(64,64,32)" >output/32_4_output.txt
./main3d.gnu.x86-milan.TPROF.ex inputs nbins=32 domain="(256,256,256)" max_grid_size="(64,32,32)" >output/32_8_output.txt
./main3d.gnu.x86-milan.TPROF.ex inputs nbins=32 domain="(256,256,256)" max_grid_size="(32,32,32)" >output/32_16_output.txt


