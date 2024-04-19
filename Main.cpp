#include "TestHarness.h"
#include <iostream>
#include "Game.hpp"

int main()
{
  // random number generator used in some tests
  srand(::time_t(NULL));

  TestResult tr;
  TestRegistry::runAllTests(tr);

  func();

  return 0;
}
