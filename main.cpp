/**
 * @file main.cpp
 * @author DSN
 * @brief Play the 15 Puzzle game!
 * @version 0.3
 * @date 2023-10-12
 */

/**
 * @mainpage
 * Let's play a game of 15 Puzzle!
 * 
 * <p>
 * Reference: [Learn C++: Project](https://www.learncpp.com/cpp-tutorial/chapter-21-project/)
 */

#include "board.h"
#include "userInput.h"
#include "direction.h"
#include "random.h"
#include <iostream>

namespace Setup
{
    constexpr std::size_t minMoves{ 10 };
    constexpr std::size_t maxMoves{ 100 };

    void puzzleToSolve(Board& board)
    {
        for (std::size_t i{}; i < Random::get(minMoves, maxMoves); ++i)
            board.moveTile(getRandomDirection());
    }
}

int main()
{    
    Board& board{ Board::init() };
    // You cannot copy a singleton. (Not sure about move.)
    // Nevertheless, you can reference it.
    
    Setup::puzzleToSolve(board);    
    std::cout << board;    
    do
    {                
        try
        {
            // we ensure that \c getDirection() is called using a valid user input
            Direction dir{ UserInput::getDirection(UserInput::getKey()) };            
            board.moveTile(dir);
            std::cout << board;
        }
        catch(Direction quit)
        {
            // Since a valid key is passed to \c getDirection()
            // and the only valid key that's not a direction is `q`,
            // we are assured that if \c getDirection() throws, it only does so because the user wanted to quit.
            std::cout << "\n\nBye!\n\n";
            return 0;
        }

    } while (not gameOver(board));

    std::cout << "\n\nYou Won!!\n\n";
    return 0;
}
