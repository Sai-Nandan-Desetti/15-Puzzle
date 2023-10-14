/**
 * @file random.h
 * @author DSN
 * @brief Defines a namespace that encapsulates logic pertaining to the random generation of a number in a given range.
 * @version 0.1
 * @date 2023-08-18
 * 
 */

#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <chrono>

namespace Random
{
    /**
     * @brief Generates a Mersenne Twister object
     * 
     * @return std::mt19937 
     */
    inline std::mt19937 generate()
    {
        std::random_device rd{};

        std::seed_seq ss{
            static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
            rd(), rd(), rd()
        };

        return std::mt19937{ ss };
    }

    inline std::mt19937 mt{ generate() };

    /**
     * @brief Generates a number in the range \c [min,max]
     * 
     * @details The random variable follows a uniform distribution.
     * 
     * @param min 
     * @param max 
     * @return std::size_t 
     */
    inline std::size_t get(std::size_t min, std::size_t max)
    {
        return std::uniform_int_distribution{min, max}(mt);
    }
}

#endif
