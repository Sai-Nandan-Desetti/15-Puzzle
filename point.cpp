#include "point.h"

Point Point::getAdjacentPoint(Direction dir)
{
    return *this + Point{ directions[+dir] };
}

Point operator+(Point a, Point b)
{       
    return { a.m_x + b.m_x, a.m_y + b.m_y };
}
