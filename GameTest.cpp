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

    game.interpretBitMove(0x11111111);

    CHECK_EQUAL("00", game.board.getCoordinateFromBits(game.move_description["origin"][0]) );
    CHECK_EQUAL('0', game.board.val_to_piece[game.move_description["o_piece"][0]]);
    CHECK_EQUAL("00", game.board.getCoordinateFromBits(game.move_description["destination"][0]) );
    CHECK_EQUAL('0', game.board.val_to_piece[game.move_description["d_piece"][0]] );
    CHECK_EQUAL("00", game.board.getCoordinateFromBits(game.move_description["promotion"][0]));
}
    
TEST(Game, Move_Pieces) {
    Game game;
    game.movePiece("e2-e4");

    game.board.printBoard();

}
    