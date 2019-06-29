AUX_SOURCE_DIRECTORY(. DIR_TEST1_SRCS)
include_directories( . /ldfssz1/MGI_ALGORITHM/assembly/wengjiancong/My_software/Cplusplus/eigen-eigen-b9cd8366d4e8)
ADD_LIBRARY ( Test ${DIR_TEST1_SRCS})
add_definitions(-std=c++11)
