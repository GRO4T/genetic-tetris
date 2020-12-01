#ifndef TETROMINO_GENERATOR_HPP
#define TETROMINO_GENERATOR_HPP

#include <vector>

#include "tetromino.hpp"

class TetrominoGenerator {
public:
    static const std::vector<Tetromino> TETROMINOES;

    TetrominoGenerator() = default;
    Tetromino getTetromino() const;
};

#endif