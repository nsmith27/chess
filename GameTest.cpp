#include "Game.h"
#include "TestHarness.h"

TEST(Game, Interpret_Coordinates_on_Initialization) {
    Game game;

    CHECK_EQUAL(0, game.move_description["origin"][0]);
    CHECK_EQUAL(0, game.move_description["o_piece"][0]);
    CHECK_EQUAL(0, game.move_description["destination"][0]);
    CHECK_EQUAL(0, game.move_description["d_piece"][0]);
    CHECK_EQUAL(0, game.move_description["promotion"][0]);
}
    
TEST(Game, Interpret_Coordinates) {
    Game game;

    game.interpretMove(0x11111111);

    CHECK_EQUAL(1, game.move_description["origin"][0]);
    CHECK_EQUAL(1, game.move_description["o_piece"][0]);
    CHECK_EQUAL(1, game.move_description["destination"][0]);
    CHECK_EQUAL(1, game.move_description["d_piece"][0]);
    CHECK_EQUAL(1, game.move_description["promotion"][0]);


}
    