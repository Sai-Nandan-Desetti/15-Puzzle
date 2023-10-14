#include "board.h"
#include <stdexcept>
#include <utility>

Tile Board::operator[](const Point& point) const
{   
    // note that the coordinates of `point` could be negative 
    int x{ point.getX() };
    int y{ point.getY() };

    if (x < 0 or x >= m_size or y < 0 or y >= m_size)
        throw std::out_of_range("You're thinking OUT of the box!");

    return m_tiles[x][y];
}

Tile& Board::operator[](const Point& point)
{
    // note that the coordinates of `point` could be negative 
    int x{ point.getX() };
    int y{ point.getY() };

    if (x < 0 or x >= m_size or y < 0 or y >= m_size)
        throw std::out_of_range{ "You're thinking 'OUT' of the box!" };

    return m_tiles[x][y];
}

Board& Board::init(Size size)
{
    static Board board{ size };

    for (Index i{}; i < board.m_size; ++i)
        for (Index j{}; j < board.m_size; ++j)        
            // Have to use direct initialization here, otherwise compiler cries of narrowing conversion:
            // `i`, `j`, and `board.m_size` are of type `int` and Tile expects a `std::size_t` argument.
            board.m_tiles[i][j] = Tile(i * board.m_size + j + 1);        
    
    // the last tile must be empty    
    board.m_tiles[board.m_size - 1][board.m_size - 1] = Tile{};
    board.m_emptyPoint = Point{ board.m_size-1, board.m_size-1 };

    return board;
}

/**
 * @details
 * - If the direction is valid, then the empty tile is swapped with the appropriate adjacent tile.
 *  - The adjacent tile is found by finding the appropriate \c Point adjacent to the \c Board::m_emptyPoint. 
 * - If the direction is invalid, in the sense that the empty tile will have to be kicked out of the box, we leave the board as is.
 * 
 * - The number of correct tiles needs to be updated carefully.
 *  - Particularly, if a tile was already in a wrong position, and continues to be in a wrong position in the next move, the number of correct tiles shouldn't be decreased again!
 * 
 * - Update the coordinates of the empty tile.
 */
void Board::moveTile(Direction dir) noexcept
{   
    // find the adjacent point in the opposite direction 
    Point nextPoint{ m_emptyPoint.getAdjacentPoint(-dir) };       
    try
    {        
        bool checkEmpty{ (*this)[m_emptyPoint].isCorrectPosition() };
        bool checkNext{ (*this)[nextPoint].isCorrectPosition() };

        swapTiles((*this)[nextPoint], (*this)[m_emptyPoint]);

        m_numCorrectTiles += (*this)[m_emptyPoint].isCorrectPosition() ? 1 : (-1 * checkEmpty);
        m_numCorrectTiles += (*this)[nextPoint].isCorrectPosition() ? 1 : (-1 * checkNext);
        
        m_emptyPoint = std::move(nextPoint);
    }
    catch(std::out_of_range& e)
    {        
        // If out of bounds, do nothing.
        // There's no point printing the message because we're going to be clearing the screen immediately to print the board anyway.        
    }    
}

Board::Size Board::getNumberOfCorrectTiles() const
{
    return m_numCorrectTiles;
}

bool gameOver(Board& board)
{    
    return board.m_numCorrectTiles == board.m_size * board.m_size;
}

std::ostream& operator<<(std::ostream& out, const Board& board)
{
    Board::clearScreen();

    for (Board::Index i{}; i < board.m_size; ++i)
    {
        for (Board::Index j{}; j < board.m_size; ++j)
            out << board.m_tiles[i][j];
        
        out << '\n';
    }        

    return out;
}
