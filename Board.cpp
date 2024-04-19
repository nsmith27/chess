#include "Board.h"

#include <sstream>

#include "printer.h"

Board::Board() {
    grid = { static_cast<int32_t>(0xCEDBADEC),
            static_cast<int32_t>(0xFFFFFFFF),
            0x00000000,
            0x00000000,
            0x00000000,
            0x11111111,
            0x42356324 };

    piece_to_val = { {'-', 0},  {'P', 1},  {'N', 2},  {'B', 3},  {'R', 4},
                    {'Q', 5},  {'K', 6},  {'p', 15}, {'n', 14}, {'b', 13},
                    {'r', 12}, {'q', 11}, {'k', 10} };

    val_to_piece = { {0, '-'},  {1, 'P'},  {2, 'N'},  {3, 'B'},  {4, 'R'},
                    {5, 'Q'},  {6, 'K'},  {15, 'p'}, {14, 'n'}, {13, 'b'},
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
    std::string sep = " |";
    for (auto row : grid) {
        for (int i = 7; i >= 0; i--) {
            char piece = val_to_piece[(row >> i * 4) & 15];
            ss << piece << sep;
        }
        ss << '\n';
    }
}

void Board::getBitStream(std::stringstream& ss) {
    std::string sep = " ";
    for (auto row : grid) {
        for (int i = 31; i >= 0; i--) {
            ss << ((row >> i) & 1);
            if (i % 4 == 0) {
                ss << sep;
            }
        }
        ss << '\n';
    }
}

uint8_t Board::getCoordinate(std::string coord) {
    uint8_t row = static_cast<uint8_t>(coord[1] - '1');
    uint8_t col = static_cast<uint8_t>(coord[0] - 'a');
    if (row < 0 or row > 7 or col < 0 or col > 7) {
        std::cerr << "Coordinate out of bounds." << std::endl;
        return 255;
    }
    uint8_t result = (row * 8) + col;
    return result;
}