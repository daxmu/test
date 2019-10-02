# pragma once

void naiveCpuGemmFloat(void* srcA, void* srcB, void* dstC, int M, int N, int K);

template<typename T>
void naiveCpuGemm(T* srcA, T* srcB, T* dstC, int M, int N, int K);