//
//  Calculator.cpp
//  question1
//
//  Created by Seungyong Lee on 2017. 4. 16..
//  Copyright © 2017년 Seungyong Lee. All rights reserved.
//

#include <iostream>
#include "Calculator.hpp"

void Calculator::Init()
{
    cntAdd=cntMin=cntDiv=cntMul=0;
}

float Calculator::Add(float x, float y)
{
    cntAdd ++;
    return x+y;
}

float Calculator::Min(float x, float y)
{
    cntMin++;
    return x-y;
}

float Calculator::Div(float x, float y)
{
    cntDiv++;
    return x/y;
}

float Calculator::Mul(float x, float y)
{
    cntMul++;
    return x*y;
}

void Calculator::ShowOpCount()
{
    std::cout<<"덧셈 : "<<cntAdd<<' '<<"뺄셈 : "<<cntMin<<' '<<"곱셈 : "<<cntMul<<' '<<"나눗셈 : "<<cntDiv<<std::endl;
}
