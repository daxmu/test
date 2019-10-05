#include<iostream>
#include "gemm.h"

using namespace std;

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

template<typename T>
void naiveCpuGemm2(T* srcA, T* srcB, T* dstC, int M, int N, int K){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            dstC[i*N + j] = 0;
        }
    }
    for(int k = 0; k < K; k++){
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                dstC[i*N + j] += srcA[i*K + k] * srcB[k*N + j];
            }
        }
    }
}

void naiveCpuGemmFloat(void* srcA, void* srcB, void* dstC, int M, int N, int K){
    //naiveCpuGemm(static_cast<float*>(srcA), static_cast<float*>(srcB), static_cast<float*>(dstC), M, N, K);
    naiveCpuGemm2(static_cast<float*>(srcA), static_cast<float*>(srcB), static_cast<float*>(dstC), M, N, K);
}
