//
//  main.cpp
//  question1
//
//  Created by Seungyong Lee on 2017. 4. 16..
//  Copyright © 2017년 Seungyong Lee. All rights reserved.
//

#include <iostream>
#include "Calculator.hpp"

int main(int argc, const char * argv[]) {
    Calculator cal;
    cal.Init();
    std::cout<<"3.2 + 2.4 = "<<cal.Add(3.2, 2.4)<<std::endl;
    std::cout<<"3.5 / 1.7 = "<<cal.Div(3.5, 1.7)<<std::endl;
    std::cout<<"2.2 - 1.5 = "<<cal.Min(2.2, 1.5)<<std::endl;
    std::cout<<"4.9 / 1.2 = "<<cal.Div(4.9, 1.2)<<std::endl;
    cal.ShowOpCount();
    
    return 0;
}
