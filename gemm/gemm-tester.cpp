#include <iostream>
#include <chrono>

#include "tensor.h"
#include "gemm.h"

int main(){

    int gemmM, gemmN, gemmK;
    std::cin >> gemmM >> gemmN >> gemmK;

    float initValue;
    int iterations;
    bool printOutput;
    std::cin >> initValue >> iterations >> printOutput;
    
    const int elementA = gemmM * gemmK;
    const int elementB = gemmK * gemmN;
    const int elementC = gemmM * gemmN;
    
    Tensor tensorA(elementA, "matrixA");
    Tensor tensorB(elementB, "matrixB");
    Tensor tensorC(elementC, "matrixC");

    tensorA.init(initValue);
    tensorB.init(initValue);
    tensorC.init(initValue);
    
    // tensorA.print();
    // tensorB.print();
    // tensorC.print();

    std::cout << "[I] Warm up... " << std::endl;
    naiveCpuGemmFloat(tensorA.getPtr(), tensorB.getPtr(), tensorC.getPtr(), gemmM, gemmN, gemmK);   
    
    std::cout << "[I] Run kernel with iteration " << iterations << "..." << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0 ; i < iterations; i++){
        naiveCpuGemmFloat(tensorA.getPtr(), tensorB.getPtr(), tensorC.getPtr(), gemmM, gemmN, gemmK);   
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration<double>(end - start); 
    
    std::cout << "Time: " << duration.count() / iterations << std::endl;

    if(printOutput){
        tensorA.print();
        tensorB.print();
        tensorC.print();
    }


    return 0;
}