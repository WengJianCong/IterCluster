#!/bin/bash

CC=/share/app/gcc-5.2.0/bin/gcc CXX=/share/app/gcc-5.2.0/bin/g++ /ldfssz1/MGI_ALGORITHM/assembly/wengjiancong/My_software/cmake-3.14.3-Linux-x86_64/bin/cmake .
#-DBUILD_SHARED_LIBS=ON -DCGATOOLS_IS_PIPELINE=ON -DBOOST_ROOT=/ldfssz1/MGI_ALGORITHM/assembly/huangweihua/bin/boost_1_46_1 -DCMAKE_BUILD_TYPE=Debug  ..

if [ -f ./Makefile ]; then
    make
else
    echo "Errors executing CMake. Fix errors and run again."
fi

mv main IterCluster-MCL
