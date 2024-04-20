#include <sstream>
#include <string>

#include "Board.h"
#include "TestHarness.h"
#include "printer.h"

TEST(Board, Get_Coordinate_From_Move) {
    Board board;

    // Test valid coordinates
    CHECK_EQUAL(0, board.getCoordinateFromMove("a1"));
    CHECK_EQUAL(1, board.getCoordinateFromMove("b1"));
    CHECK_EQUAL(7, board.getCoordinateFromMove("h1"));
    CHECK_EQUAL(8, board.getCoordinateFromMove("a2"));
    CHECK_EQUAL(12, board.getCoordinateFromMove("e2"));
    CHECK_EQUAL(63, board.getCoordinateFromMove("h8"));

    // Test out of bounds coordinates
    CHECK_EQUAL(255, board.getCoordinateFromMove("i1"));  // col out of bounds
    CHECK_EQUAL(255, board.getCoordinateFromMove("a9"));  // row out of bounds
    CHECK_EQUAL(255, board.getCoordinateFromMove("h9"));  // both out of bounds
    CHECK_EQUAL(255, board.getCoordinateFromMove("j9"));  // both out of bounds
}

TEST(Board, Get_Coordinate_From_Bits) {
    Board board;

    // Test valid coordinates
    CHECK_EQUAL("a1", board.getCoordinateFromBits(0));
    CHECK_EQUAL("b1", board.getCoordinateFromBits(1));
    CHECK_EQUAL("h1", board.getCoordinateFromBits(7));
    CHECK_EQUAL("a2", board.getCoordinateFromBits(8));
    CHECK_EQUAL("e2", board.getCoordinateFromBits(12));
    CHECK_EQUAL("h8", board.getCoordinateFromBits(63));

    // Test out of bounds coordinates
    CHECK_EQUAL("00", board.getCoordinateFromBits(64));  // col out of bounds
    CHECK_EQUAL("00", board.getCoordinateFromBits(-1));  // row out of bounds
}

TEST(Board, Read_Board_as_Bits) {
    Board board;

    std::string bit_board =
        "1100 1110 1101 1011 1010 1101 1110 1100 \n"
        "1111 1111 1111 1111 1111 1111 1111 1111 \n"
        "1000 1000 1000 1000 1000 1000 1000 1000 \n"
        "1000 1000 1000 1000 1000 1000 1000 1000 \n"
        "1000 1000 1000 1000 1000 1000 1000 1000 \n"
        "1000 1000 1000 1000 1000 1000 1000 1000 \n"
        "0001 0001 0001 0001 0001 0001 0001 0001 \n"
        "0100 0010 0011 0101 0110 0011 0010 0100 \n";

    std::stringstream bs;
    board.getBitStream(bs);
    CHECK_EQUAL(bit_board, bs.str());
}

TEST(Board, Read_Board_as_Chars) {
    Board board;

    std::string char_board =
        "|r| |n| |b| |q| |k| |b| |n| |r| \n"
        "|p| |p| |p| |p| |p| |p| |p| |p| \n"
        "|-| |-| |-| |-| |-| |-| |-| |-| \n"
        "|-| |-| |-| |-| |-| |-| |-| |-| \n"
        "|-| |-| |-| |-| |-| |-| |-| |-| \n"
        "|-| |-| |-| |-| |-| |-| |-| |-| \n"
        "|P| |P| |P| |P| |P| |P| |P| |P| \n"
        "|R| |N| |B| |Q| |K| |B| |N| |R| \n";

    std::stringstream bs;
    board.getBoardStream(bs);
    CHECK_EQUAL(char_board, bs.str());
}
