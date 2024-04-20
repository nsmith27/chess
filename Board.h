#pragma once

#include <iostream>
#include <map>
#include <vector>

class Board {
   private:
    std::vector<int32_t> grid;
    // Piece Values in Grid
    // 0 => 0000, P => 0001, N => 0010, B => 0011, R => 0100, Q => 0101,
    // K => 0110, E => 0111, - => 1000, e => 1001, k => 1010, q => 1011, 
    // r => 1100, b => 1101, n => 1110, p => 1111,

   public:
    std::map<int8_t, char> piece_to_val;
    std::map<int8_t, char> val_to_piece;

    Board();

    void printBoard();
    void printBits();
    void getBoardStream(std::stringstream& ss);
    void getBitStream(std::stringstream& ss);

    uint8_t getPiece(std::string coord);
    void setPiece(uint8_t bits_6, uint8_t piece);
    void maskBits(uint8_t piece, int row, int shift) {
    std::pair<int, int> getCoordPairFromInt(uint8_t bits_6);
    uint8_t getCoordinateFromMove(std::string coord);
    std::string getCoordinateFromBits(uint8_t bits_6);
    uint8_t getPieceFromBoard(std::string coord);
};
