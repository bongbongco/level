//
//  Calculator.hpp
//  question1
//
//  Created by Seungyong Lee on 2017. 4. 16..
//  Copyright © 2017년 Seungyong Lee. All rights reserved.
//

#ifndef Calculator_hpp
#define Calculator_hpp

class Calculator
{
private:
    int cntAdd, cntMin, cntDiv, cntMul;
    
public:
    void Init();
    float Add(float x, float y);
    float Min(float x, float y);
    float Div(float x, float y);
    float Mul(float x, float y);
    void ShowOpCount();
};

#endif /* Calculator_hpp */
