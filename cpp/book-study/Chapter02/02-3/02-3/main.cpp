//
//  main.cpp
//  02-3
//
//  Created by Seungyong Lee on 2017. 4. 16..
//  Copyright © 2017년 Seungyong Lee. All rights reserved.
//

#include <iostream>
#include "structPoint.hpp"

int main(int argc, const char * argv[]) {
    Point *ptr1 = new Point;
    Point *ptr2 = new Point;
    
    ptr1->xpos=5;
    ptr1->ypos=10;
    
    ptr2->xpos=15;
    ptr2->ypos=20;

    Point &addPtn = PtnAdder(*ptr1, *ptr2);
    std::cout << "addPtn x : "<<addPtn.xpos<<' '<<"addPtn y :"<<addPtn.ypos<<std::endl;
    return 0;
}
