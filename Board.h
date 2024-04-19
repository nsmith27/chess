#pragma once

#include <iostream>
#include <map>
#include <vector>

class Board {
   public:
    Board();

    void printBoard();
    void printBits();

   private:
    std::vector<int32_t> grid;
    std::map<int, char> piece_to_val;
    std::map<int, char> val_to_piece;


};

// Piece Values in Grid
// - -- 0000
// P -- 0001
// N -- 0010
// B -- 0011
// R -- 0100
// Q -- 0101
// K -- 0110
// E -- 0111
// - -- 1000
// e -- 1001
// k -- 1010
// q -- 1011
// r -- 1100
// b -- 1101
// n -- 1110
// p -- 1111
