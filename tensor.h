#pragma once

#include <stdio.h>
#include <malloc.h>
#include <cassert>
#include <iostream>
#include <string>

class Tensor{
public:
    Tensor(int nbElement_, std::string name_): nbElement(nbElement_), name(name_){
        const int size = 4 * nbElement_;
        ptr = malloc(size);
        assert(ptr != nullptr && "failed when allocate tensor");

        std::cout << "[I] Creating tensor " << name << ", "
            << size << " bytes memory allocated at " << ptr << std::endl;
    }
    ~Tensor(){
        assert(ptr != nullptr);
        std::cout << "[I] Free tensor " << name << std::endl;
        free(ptr);
    }
    void* getPtr(){return ptr;}

    void init(float value = 1) {
        std::cout << "[I] Init tensor " << name << " with value " << value << std::endl;
        float* t = static_cast<float*>(ptr);
        for(int i = 0; i < nbElement; i++){
            t[i] = value;
        }
    }

    void print() const {
        std::cout << "[I] Print tensor " << name << " with " << nbElement << " elements" << std::endl;
        const float* t = static_cast<float*>(ptr);
        for(int i = 0; i < nbElement; i++){
            std::cout << t[i] << " ";
            if(i % 16 == 15)
                std::cout << std::endl;
        }
        std::cout << std::endl;
    }
private:
    void* ptr;
    int nbElement;
    std::string name;
};