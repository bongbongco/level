//
//  main.cpp
//  question2
//
//  Created by Seungyong Lee on 2017. 4. 16..
//  Copyright © 2017년 Seungyong Lee. All rights reserved.
//

#include <iostream>
#include "PrinterManager.hpp"

int main(int argc, const char * argv[]) {
    Printer pnt;
    pnt.SetString("Hello world!");
    pnt.ShowString();
    
    pnt.SetString("I love C++");
    pnt.ShowString();
    return 0;
}
