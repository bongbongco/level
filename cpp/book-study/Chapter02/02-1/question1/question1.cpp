#include <iostream>
#include "question1-header.h"
int main() {
    int num1=20, num2=30;
    
    std::cout<<"num1 : "<<num1<<' '<<"num2 : "<<num2<<std::endl;
    AddNum(num1, num2);
    std::cout<<"num1 : "<<num1<<' '<<"num2 : "<<num2<<std::endl;
    EditSigned(num1);
    std::cout<<"num1 : "<<num1<<' '<<"num2 : "<<num2<<std::endl;
    EditSigned(num2);
    std::cout<<"num1 : "<<num1<<' '<<"num2 : "<<num2<<std::endl;
    return 0;
}
