#include "TestHarness.h"
#include <iostream>
#include "Game.h"
#include "Piece.h"
#include "Board.h"

int main()
{
  // random number generator used in some tests
  srand(::time_t(NULL));

  TestResult tr;
  TestRegistry::runAllTests(tr);

  // ChessColor::Color color = ChessColor::WHITE;

  Board b; 
  b.printBits();
  b.printBoard();


  return 0;
}
