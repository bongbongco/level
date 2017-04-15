//
//  structPoint.hpp
//  02-3
//
//  Created by Seungyong Lee on 2017. 4. 16..
//  Copyright © 2017년 Seungyong Lee. All rights reserved.
//

#ifndef structPoint_hpp
#define structPoint_hpp

typedef struct __Point
{
    int xpos;
    int ypos;
} Point;

Point& PtnAdder(const Point &p1, const Point &p2);

#endif /* structPoint_hpp */
