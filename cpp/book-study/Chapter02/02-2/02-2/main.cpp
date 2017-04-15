#include <iostream>
#include "printconst.hpp"

int main(int argc, const char * argv[]) {
    const int num=12;
    const int *ptr = &num;
    const int *(&ref)=ptr;
    
    std::cout<<"*ptr : ";printconst(ptr);
    std::cout<<"*(&ref) : ";printconst(ref);
    return 0;
}
