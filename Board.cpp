#include "Board.h"

#include <sstream>

#include "printer.h"

Board::Board() {
    // Board starts at square "a1" 
    grid = { 
            static_cast<int32_t>(0x42356324),
            static_cast<int32_t>(0x11111111),
            static_cast<int32_t>(0x88888888),
            static_cast<int32_t>(0x88888888),
            static_cast<int32_t>(0x88888888),
            static_cast<int32_t>(0x88888888),
            static_cast<int32_t>(0xFFFFFFFF),
            static_cast<int32_t>(0xCEDBADEC),
            };

    piece_to_val = { {'0', 0},  {'P', 1},  {'N', 2},  {'B', 3},  {'R', 4},
                    {'Q', 5},  {'K', 6},  {'-', 8}, {'p', 15}, {'n', 14}, {'b', 13},
                    {'r', 12}, {'q', 11}, {'k', 10} };

    val_to_piece = { {0, '0'},  {1, 'P'},  {2, 'N'},  {3, 'B'},  {4, 'R'},
                    {5, 'Q'},  {6, 'K'},  {8, '-'}, {15, 'p'}, {14, 'n'}, {13, 'b'},
                    {12, 'r'}, {11, 'q'}, {10, 'k'} };
}

void Board::printBoard() {
    std::stringstream ss;
    getBoardStream(ss);
    print(ss.str());
}

void Board::printBits() {
    std::stringstream ss;
    getBitStream(ss);
    print(ss.str());
}

void Board::getBoardStream(std::stringstream& ss) {
    std::string sep = "| ";
    for (int row = 7; row >= 0; --row) {
        for (int i = 7; i >= 0; i--) {
            char piece = val_to_piece[(grid[row] >> i * 4) & 15];
            ss << "|" << piece << sep;
        }
        ss << '\n';
    }
}

void Board::getBitStream(std::stringstream& ss) {
    std::string sep = " ";
    for (int row = 7; row >= 0; --row) {
        for (int i = 31; i >= 0; i--) {
            ss << ((grid[row] >> i) & 1);
            if (i % 4 == 0) {
                ss << sep;
            }
        }
        ss << '\n';
    }
}

uint8_t Board::getCoordinateFromMove(std::string coord) {
    uint8_t row = static_cast<uint8_t>(coord[1] - '1');
    uint8_t col = static_cast<uint8_t>(coord[0] - 'a');
    if (row < 0 or row > 7 or col < 0 or col > 7) {
        std::cerr << "Coordinate out of bounds." << std::endl;
        return 255;
    }
    uint8_t result = (row * 8) + col;
    return result;
}

void Board::setPiece(uint8_t bits_6, uint8_t piece){
    std::pair<int, int> coord = getCoordPairFromInt(bits_6);
    maskBits(piece, coord.first, 8 - coord.second * 4);
}

void Game::maskBits(uint8_t piece, int row, int shift) {
    uint32_t clear_space = -1;
    uint32_t place_piece = (0 << shift);
    uint32_t mask = clear_space ^ place_piece;
    print("~~~~>>>", clear_space, place_piece, mask)
    grid[row] = (grid[row] & mask);
}

std::pair<int, int> Board::getCoordPairFromInt(uint8_t bits_6){
    if (bits_6 < 0 or bits_6 > 63) {
        std::cerr << "Something went wrong!  Stored coordinate " << bits_6 << " is out of bounds." << std::endl;
        std::pair<uint8_t, uint8_t> err {255, 255};
        return err;
    }
    std::pair<uint8_t, uint8_t> coord {(bits_6 % 8), (bits_6 / 8)};
    return coord;
}


std::string Board::getCoordinateFromBits(uint8_t bits_6){
    if (bits_6 < 0 or bits_6 > 63) {
        std::cerr << "Something went wrong!  Stored coordinate " << bits_6 << " is out of bounds." << std::endl;
        return "00";
    }
    char alpha = 'a' + (bits_6 % 8);
    char num = '1' + (bits_6 / 8);
    return std::string(1, alpha) + std::string(1, num);
}
