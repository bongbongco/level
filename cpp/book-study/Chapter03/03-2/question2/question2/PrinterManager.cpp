//
//  PrinterManager.cpp
//  question2
//
//  Created by Seungyong Lee on 2017. 4. 16..
//  Copyright © 2017년 Seungyong Lee. All rights reserved.
//
#include <iostream>
#include <cstdlib>
#include "PrinterManager.hpp"

void Printer::SetString(std::string str)
{
    if(str.length()<500){
        savedStr.swap(str);
    }else{
        std::cout<<"To much length"<<std::endl;
        exit(1);
    }
    
}

void Printer::ShowString()
{
    std::cout<<savedStr<<std::endl;
}
