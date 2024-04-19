#include "TestHarness.h"
#include "Board.h"

TEST(Board, GetCoordinate) {
    Board board;

    // Test valid coordinates
    CHECK_EQUAL(0, board.getCoordinate("a1"));
    CHECK_EQUAL(1, board.getCoordinate("b1"));
    CHECK_EQUAL(7, board.getCoordinate("h1"));
    CHECK_EQUAL(8, board.getCoordinate("a2"));
    CHECK_EQUAL(63, board.getCoordinate("h8"));

    // Test out of bounds coordinates
    CHECK_EQUAL(255, board.getCoordinate("i1")); // col out of bounds
    CHECK_EQUAL(255, board.getCoordinate("a9")); // row out of bounds
    CHECK_EQUAL(255, board.getCoordinate("h9")); // both out of bounds
    CHECK_EQUAL(255, board.getCoordinate("j9")); // both out of bounds
}
