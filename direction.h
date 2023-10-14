/**
 * @file direction.h
 * @author DSN
 * @brief Defines a \c Direction
 * @version 0.1
 * @date 2023-10-13
 */

#ifndef DIRECTION_H
#define DIRECTION_H

#include <string_view>
#include <vector>
#include <iostream>

/**
 * @brief Defines the cardinal directions.
 * @details We define four of them:
 * - UP (corresponds to 'w')
 * - LEFT (corresponds to 'a')
 * - DOWN (corresponds to 's')
 * - RIGHT (corresponds to 'd')
 */
enum class Direction
{
    up,
    left,
    down,
    right,
    max_directions    
};

using enum Direction;

using Cell = std::pair<int, int>;
inline const std::vector<Cell> directions{ {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

/**
 * @brief Get the string form of a given direction
 * 
 * @param dir: A \c Direction value 
 * @return std::string_view 
 */
std::string_view getName(Direction dir);

/**
 * @brief Return an unsinged int form of a given direction
 * 
 * @param dir: A \c Direction value 
 * @return std::size_t 
 */
std::size_t operator+(Direction dir);

/**
 * @brief Output the string form of \c dir
 * 
 * @param out
 * @param dir 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out, Direction dir);

/**
 * @brief Randomly pick a direction
 * 
 * @return Direction 
 */
Direction getRandomDirection();

#endif
