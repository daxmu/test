cmake_minimum_required (VERSION 2.6)
project (dl_performance)
include_directories(.)

file(GLOB SRCFILES
    "*.h"
    "*.cpp"
    "gemm/*.h"
    "gemm/*.cpp"
)

add_executable(gemm-tester ${SRCFILES})