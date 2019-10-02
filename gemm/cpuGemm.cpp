#include<iostream>
#include "gemm.h"

using namespace std;

void naiveCpuGemmFloat(void* srcA, void* srcB, void* dstC, int M, int N, int K){
    naiveCpuGemm(static_cast<float*>(srcA), static_cast<float*>(srcB), static_cast<float*>(dstC), M, N, K);
}

template<typename T>
void naiveCpuGemm(T* srcA, T* srcB, T* dstC, int M, int N, int K){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            float result = 0;
            for(int k = 0; k < K; k++){
                result += srcA[i*K + k] * srcB[k*N + j];
            }
            dstC[i*N + j] = result;
        }
    }
}