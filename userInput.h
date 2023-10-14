/**
 * @file userInput.h
 * @author DSN
 * @brief Defines the \c UserInput namespace
 * @version 0.2
 * @date 2023-10-13
 */

#ifndef USERINPUT_H
#define USERINPUT_H

#include "direction.h"
#include <iostream>
#include <set>
#include <limits>

/**
 * @brief Handles input from the user
 * @details
 * Has two main purposes:
 * - Get input from the user.
 * - Handle invalid input.
 */
namespace UserInput
{
    /**
     * @brief helper function to ignore extraneous characters in the input buffer.     
     */
    void ignoreLine()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    /**
     * @brief helper function the cleans up the input stream,
     * assisting in getting valid input from the user.     
     */
    void inputCleanup()
    {
        if (!std::cin)
        {
            if (std::cin.eof())
                exit(0);
            
            std::cin.clear();
            ignoreLine();
        }
        else
            ignoreLine();
    }

    std::set<char> validCommands{ 'w', 'a', 's', 'd', 'q' };

    /**
     * @brief Check the validity of user's command.
     * 
     * @param ch: Command entered by the user. 
     * @return true: if valid;
     * @return false: otherwise. 
     */
    bool isValidCommand(char ch)
    {
        return validCommands.find(ch) != validCommands.end();
    }

    /**
     * @brief Get input from the user.
     * 
     * @return char: a valid character input from the user.
     */
    char getKey()
    {
        char choice{};        
        while(true)
        {
            std::cin >> choice;            
            if (isValidCommand(choice))
                break;
            inputCleanup();
        }        
        
        return choice;
    }
        
    /**
     * @brief Get a \c Direction value from a user-entered \c key
     * @details If the key is not one of the \c UserInput::validCommands, a default \c Direction value (\c Direction::max_directions) is thrown.
     * 
     * @param key: A character entered by the user to slide a tile 
     * @return Direction 
     */
    Direction getDirection(char key)
    {
        switch (key)
        {
        case 'w':
            return up;
        case 'a':
            return left;
        case 's':
            return down;
        case 'd':
            return right;    
        default:
            throw max_directions;
        }
    }
};

#endif
