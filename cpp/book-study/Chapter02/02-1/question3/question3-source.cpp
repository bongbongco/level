#include <iostream>
#include "question3-header.h"

void SwapPointer(int *(&ptr1), int *(&ptr2))
{
    int *temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
}
