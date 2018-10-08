CMAKE_MINIMUM_REQUIRED(VERSION 2.8) 

project(LFR-matrix-build)

set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/../bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

#set(CMAKE_C_COMPILER "/share/app/gcc-5.2.0/bin/g++")
#set(CMAKE_CXX_COMPILER "/share/app/gcc-5.2.0/bin/g++")


set(CMAKE_CXX_FLAGS "-std=c++98 -O3 -DKVALUE=17") 

include_directories(${PROJECT_SOURCE_DIR})


include(${PROJECT_SOURCE_DIR}/Utils/compiler.cmake)
include(${PROJECT_SOURCE_DIR}/ThirdParty/compiler.cmake)
include(${PROJECT_SOURCE_DIR}/IOUtils/compiler.cmake)
include(${PROJECT_SOURCE_DIR}/test/compiler.cmake)

set(source_cpp ${source_cpp}
     Global.cpp
     IndexKmer.cpp
     Read2KmerCount.cpp
     Kmer2BarcodeHash.cpp
     BarcodeMutrix.cpp
)

set(source_h ${source_h}
     Global.h
     Logic.h
)

add_executable(LFR-matrix-build-debug01 ${source_h} ${source_cpp} main.cpp)
#add_executable(LFR-matrix-test ${source_h} ${source_cpp}  ${test_cpp} test.cpp)

target_link_libraries(LFR-matrix-build-debug01 -lpthread -lz)
#target_link_libraries(LFR-matrix-test -lpthread -lz)
