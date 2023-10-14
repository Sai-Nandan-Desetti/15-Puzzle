/**
 * @file board.h
 * @author DSN
 * @brief Defines a \c Board 
 * @version 0.1
 * @date 2023-10-12 
 */

#ifndef BOARD_H
#define BOARD_H

#include "tile.h"
#include "direction.h"
#include "point.h"
#include <memory>
#include <iostream>

/**
 * @brief Defines the board for the game.
 * @details Since there can be only one board for the game, \c Board is defined as a singleton. 
 */
class Board
{
private:
    // Size is kept `int` (rather than `std::size_t`) because we want negative indices.
    using Size = int;
    using Index = Size;
    using Row = std::unique_ptr<Tile[]>;      

public:
    using Grid = std::unique_ptr<Row[]>;

private:
    // In this project, by default, we play the 15 Puzzle game.
    static constexpr Size s_defaultSize{ 4 };

    /**
     * @brief The size of the board.
     * @details The board is assumed to be a square.
     */
    Size m_size{};

    /**
     * @brief A 2d grid of tiles.     
     */
    Grid m_tiles{};
    
    /**
     * @brief The coordinates of the empty tile.
     * @details We maintain the state of the empty tile to avoid having to search the entire board to find the empty tile.
     */
    Point m_emptyPoint{};

    /**
     * @brief Count of the number of tiles in their correct position.
     * @details We maintain this info so that we can check if the game is over or not in O(1) time.
     */
    Size m_numCorrectTiles{};

    
    Board(Size size) : m_size{ size }, m_numCorrectTiles{ size * size }
    {        
        m_tiles = std::make_unique<Row[]>(m_size);
        for (Index i{}; i < m_size; ++i)
            m_tiles[i] = std::make_unique<Tile[]>(m_size);        
    }
    
    /**
     * @brief Clears screen such that the board can be printed at the top.     
     */
    static void clearScreen()
    {
        // ref: https://stackoverflow.com/a/32008479
        std::cout << "\033[2J\033[1;1H";
    }
    
    Tile operator[](const Point& point) const;
    Tile& operator[](const Point& point);     

public:
    /**
     * @brief Create a static \c Board instance and initialize its grid of tiles.
     * @details
     * - The tiles are numbered from [\c 1 ... (\c size\sup{2} - 1) ] in row-major order, starting from the top-left.
     * - The \c size\sup{2}-th tile is empty.
     * @param size: The board is assumed to be a square of dimension: \c size x \c size
     * @return Board&: A reference to the static \c Board instance created. 
     */
    static Board& init(Size size = s_defaultSize);
    
    /**
     * @brief Move the empty tile in the given direction.
     * 
     * @param dir 
     */
    void moveTile(Direction dir) noexcept;

    /**
     * @brief Check if the game is over or not.
     * 
     * @return true: If the number of correct tiles equals the size of the board. 
     * @return false 
     */
    bool gameOver();
    
    /**
     * @brief Display the \c board
     * @details First clear the screen, so that the board always appears on top.
     * @param out 
     * @param board 
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream& out, const Board& board);
};

#endif
