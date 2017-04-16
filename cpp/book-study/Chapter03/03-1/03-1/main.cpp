//
//  main.cpp
//  03-1
//
//  Created by Seungyong Lee on 2017. 4. 16..
//  Copyright © 2017년 Seungyong Lee. All rights reserved.
//

#include <iostream>
#include "PointManager.hpp"

int main(int argc, const char * argv[]) {
    Point pos1={12, 4};
    Point pos2={20, 30};
    
    pos1.MovePos(-7, 10);
    pos1.ShowPosition();
    
    pos1.AddPoint(pos2);
    pos1.ShowPosition();
    
    return 0;
}
