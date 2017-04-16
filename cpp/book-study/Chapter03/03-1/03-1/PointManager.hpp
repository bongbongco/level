#ifndef PointManager_hpp
#define PointManager_hpp
#include <iostream>

struct Point
{
    int xpos;
    int ypos;
    
    void MovePos(int x, int y)
    {
        xpos += x;
        ypos += y;
    }
    
    void AddPoint(const Point &pos)
    {
        xpos += pos.xpos;
        ypos += pos.ypos;
    }
    
    void ShowPosition()
    {
        std::cout<<"["<<xpos<<", "<<ypos<<"]"<<std::endl;
    }
    
};

#endif /* PointManager_hpp */
