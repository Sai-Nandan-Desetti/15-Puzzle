#include "direction.h"
#include "random.h"

std::string_view getName(Direction dir)
{
    switch (dir)
    {
    case up:
        return "up";
    case down:
        return "down";
    case left:
        return "left";
    case right:
        return "right";    
    default:
        return "???";
    }
}

std::size_t operator+(Direction dir)
{
    return static_cast<std::size_t>(dir);
}

Direction operator-(Direction dir)
{
    switch (dir)
    {
    case up:
        return down;
    case down:
        return up;
    case left:
        return right;
    case right:
        return left;
    default:
        return dir;
    }
}

std::ostream& operator<<(std::ostream& out, Direction dir)
{    
    return out << getName(dir);
}

Direction getRandomDirection()
{
    return static_cast<Direction>(Random::get(0, +max_directions - 1));
}
