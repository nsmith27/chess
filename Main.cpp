#include <iostream>

#include "Board.h"
#include "Game.h"
#include "Piece.h"
#include "TestHarness.h"

int main() {
    // random number generator used in some tests
    srand(::time_t(NULL));

    TestResult tr;
    TestRegistry::runAllTests(tr);

    // ChessColor::Color color = ChessColor::WHITE;

    Game game;

    return 0;
}
