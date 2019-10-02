#include <iostream>

#include "tensor.h"
#include "gemm.h"

int main(){
    const int testSize = 16;
    const int gemmM = testSize;
    const int gemmN = testSize;
    const int gemmK = testSize;
    
    const int elementA = gemmM * gemmK;
    const int elementB = gemmK * gemmN;
    const int elementC = gemmM * gemmN;
    
    Tensor tensorA(elementA, "matrixA");
    Tensor tensorB(elementB, "matrixB");
    Tensor tensorC(elementC, "matrixC");

    tensorA.init();
    tensorB.init();
    tensorC.init();
    
    // tensorA.print();
    // tensorB.print();
    // tensorC.print();

    naiveCpuGemmFloat(tensorA.getPtr(), tensorB.getPtr(), tensorC.getPtr(), gemmM, gemmN, gemmK);   

    // tensorA.print();
    // tensorB.print();
    // tensorC.print();

    return 0;
}