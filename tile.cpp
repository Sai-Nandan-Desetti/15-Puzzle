#include "tile.h"

Tile::Number Tile::getNum() const
{
    return m_num;
}

Tile::Number Tile::getCorrectNum() const
{
    return m_correctNum;
}

Tile::operator bool() const
{
    return m_num != 0;
}

bool Tile::inCorrectPosition() const
{
    return m_num == m_correctNum;
}

void swapTiles(Tile& a, Tile& b)
{
    std::swap(a.m_num, b.m_num);
}

std::ostream& operator<<(std::ostream& out, const Tile& tile)
{
    Tile::Number num{ tile.getNum() };

    out << ' ';
    if (num < static_cast<Tile::Number>(10))
        out << ' ';
    if (tile)
        out << num;
    else
        out << ' ';
    out << ' ';

    return out;
}
