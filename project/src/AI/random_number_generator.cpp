/*
 * Author: Damian Kolaska
 */

#include "AI/random_number_generator.hpp"

namespace genetic_tetris {

RandomNumberGenerator::RandomNumberGenerator()
    : generator_(std::random_device{}()), dis_0_1(0.0, 1.0) {}

RandomNumberGenerator& RandomNumberGenerator::getInstance() {
    static RandomNumberGenerator instance;
    return instance;
}

float RandomNumberGenerator::random_0_1() { return dis_0_1(generator_); }

}  // namespace genetic_tetris
