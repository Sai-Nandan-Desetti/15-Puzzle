#ifndef POINT_H
#define POINT_H

#include "direction.h"

class Point
{
private:
    int m_x{};
    int m_y{};

public:
    Point(int x = 0, int y = 0) : m_x{ x }, m_y{ y }
    {        
    }

    Point(Cell cell) : m_x{ cell.first }, m_y{ cell.second }
    {        
    }
    
    int getX() const { return m_x; }
    int getY() const { return m_y; }    
    Point getAdjacentPoint(Direction dir);

    friend Point operator+(Point a, Point b);
};

#endif
