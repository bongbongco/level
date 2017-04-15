//
//  structPoint.cpp
//  02-3
//
//  Created by Seungyong Lee on 2017. 4. 16..
//  Copyright © 2017년 Seungyong Lee. All rights reserved.
//

#include <iostream>
#include "structPoint.hpp"

Point& PtnAdder(const Point &p1, const Point &p2)
{
    Point *ptn = new Point;
    ptn->xpos=p1.xpos+p2.xpos;
    ptn->ypos=p1.ypos+p2.ypos;
    
    return *ptn;
}
