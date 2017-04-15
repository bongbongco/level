#include <iostream>
#include "question3-header.h"

int main()
{
    int num1=5, num2=10;
    int *ptr1 = &num1;
    int *ptr2 = &num2;
    
    std::cout<<"ptr1 : "<<*ptr1<<' '<<"ptr2 : "<<*ptr2<<std::endl;
    std::cout<<"====SwapPointer===="<<std::endl;
    SwapPointer(ptr1, ptr2);
    std::cout<<"ptr1 : "<<*ptr1<<' '<<"ptr2 : "<<*ptr2<<std::endl;
    return 0;
}
