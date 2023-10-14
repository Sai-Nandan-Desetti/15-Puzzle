/**
 * @file tile.h
 * @author DSN
 * @brief Defines a unit \c Tile of a \c Board
 * @version 0.1
 * @date 2023-10-12 
 */

#ifndef TILE_H
#define TILE_H

#include "direction.h"
#include <iostream>

class Tile
{
public:
    using Number = std::size_t;

private:    
    
    /**
     * @brief The number the tile displays.     
     */
    Number m_num;

    /**
     * @brief The number the tile is supposed to show if it were in its correct position.     
     */
    Number m_correctNum;

public:
    /**
     * @brief Construct a \c Tile given a number     
     * 
     * @param num: the number to be assigned to the tile; by default, it's zero.
     */
    explicit Tile(Number num = 0) : m_num{ num }, m_correctNum{ num }
    {        
    }    

    /**
     * @brief Get the number corresponding to the tile
     * 
     * @return the tile number
     */
    Number getNum() const;

    /**
     * @brief Get the tile's "correct number" (see \c Number::m_correctNum)
     * 
     * @return Number 
     */
    Number getCorrectNum() const;

    /**
     * @brief A tile is empty if its number is 0.
     * 
     * @return true: the tile is non-empty 
     * @return false: it's empty 
     */
    operator bool() const;

    /**
     * @brief Check if the tile is in its correct position or not
     * 
     * @return true: If the tile displays the "correct number"
     * @return false 
     */
    bool inCorrectPosition() const;

    /**
     * @brief Swap two tiles.
     * @details We swap only the numbers they display so that their correctness can be maintained.
     * 
     * @param a 
     * @param b 
     */
    friend void swapTiles(Tile& a, Tile& b);    
};

/**
 * @brief Display a tile
 * 
 * @param out: output stream (typically, \c std::cout ) 
 * @param tile: a \c Tile object 
 * @return std::ostream&: a reference to \c out (to allow chaining of \c operator<< ) 
 */
std::ostream& operator<<(std::ostream& out, const Tile& tile);

#endif
