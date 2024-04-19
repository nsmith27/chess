#include <string>

#include "Board.h"
#include <sstream>
#include "TestHarness.h"

TEST(Board, Get_Coordinate) {
    Board board;

    // Test valid coordinates
    CHECK_EQUAL(0, board.getCoordinate("a1"));
    CHECK_EQUAL(1, board.getCoordinate("b1"));
    CHECK_EQUAL(7, board.getCoordinate("h1"));
    CHECK_EQUAL(8, board.getCoordinate("a2"));
    CHECK_EQUAL(12, board.getCoordinate("e2"));
    CHECK_EQUAL(63, board.getCoordinate("h8"));

    // Test out of bounds coordinates
    CHECK_EQUAL(255, board.getCoordinate("i1"));  // col out of bounds
    CHECK_EQUAL(255, board.getCoordinate("a9"));  // row out of bounds
    CHECK_EQUAL(255, board.getCoordinate("h9"));  // both out of bounds
    CHECK_EQUAL(255, board.getCoordinate("j9"));  // both out of bounds
}

TEST(Board, Read_Board_as_Bits) {
    Board board;

    std::string sep = " ";
    std::string bit_board =
        "1100" + sep + "1110" + sep + "1101" + sep + "1011" + sep + "1010" + sep + "1101" + sep + "1110" + sep + "1100" + sep + "\n"
        "1111" + sep + "1111" + sep + "1111" + sep + "1111" + sep + "1111" + sep + "1111" + sep + "1111" + sep + "1111" + sep + "\n"
        "0000" + sep + "0000" + sep + "0000" + sep + "0000" + sep + "0000" + sep + "0000" + sep + "0000" + sep + "0000" + sep + "\n"
        "0000" + sep + "0000" + sep + "0000" + sep + "0000" + sep + "0000" + sep + "0000" + sep + "0000" + sep + "0000" + sep + "\n"
        "0000" + sep + "0000" + sep + "0000" + sep + "0000" + sep + "0000" + sep + "0000" + sep + "0000" + sep + "0000" + sep + "\n"
        "0001" + sep + "0001" + sep + "0001" + sep + "0001" + sep + "0001" + sep + "0001" + sep + "0001" + sep + "0001" + sep + "\n"
        "0100" + sep + "0010" + sep + "0011" + sep + "0101" + sep + "0110" + sep + "0011" + sep + "0010" + sep + "0100" + sep + "\n";

    std::stringstream bs;
    board.getBitStream(bs);
    CHECK_EQUAL(bit_board, bs.str());
}

TEST(Board, Read_Board_as_Chars) {
    Board board;

    std::string sep = " |";
    std::string char_board =
    "r" + sep + "n" + sep + "b" + sep + "q" + sep + "k" + sep + "b" + sep + "n" + sep + "r" + sep + "\n"
    "p" + sep + "p" + sep + "p" + sep + "p" + sep + "p" + sep + "p" + sep + "p" + sep + "p" + sep + "\n"
    "-" + sep + "-" + sep + "-" + sep + "-" + sep + "-" + sep + "-" + sep + "-" + sep + "-" + sep + "\n"
    "-" + sep + "-" + sep + "-" + sep + "-" + sep + "-" + sep + "-" + sep + "-" + sep + "-" + sep + "\n"
    "-" + sep + "-" + sep + "-" + sep + "-" + sep + "-" + sep + "-" + sep + "-" + sep + "-" + sep + "\n"
    "P" + sep + "P" + sep + "P" + sep + "P" + sep + "P" + sep + "P" + sep + "P" + sep + "P" + sep + "\n"
    "R" + sep + "N" + sep + "B" + sep + "Q" + sep + "K" + sep + "B" + sep + "N" + sep + "R" + sep + "\n";

    std::stringstream bs;
    board.getBoardStream(bs);
    CHECK_EQUAL(char_board, bs.str());
}
