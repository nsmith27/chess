#pragma once

#include "Game.h"

#include "Board.h"
#include <iostream>
#include "printer.h"

Game::Game() {
    move_description = {
        {"origin", {0, 0, 5}},        {"o_piece", {0, 6, 9}},
        {"destination", {0, 10, 15}}, {"d_piece", {0, 16, 19}},
        {"promotion", {0, 20, 23}},
    };

    game_board.printBits();
    game_board.printBoard();
}

uint8_t Game::extractBits(const uint32_t move, const int first_bit, const int last_bit) {
    uint32_t mask = (1u << (last_bit - first_bit + 1)) - 1;
    return (move >> first_bit) & mask;
}

void Game::getMove(const uint32_t move) {
    for (auto it = move_description.begin(); it != move_description.end(); ++it) {
        uint8_t val = it->first[0];
        uint8_t first_bit = it->first[1];
        uint8_t last_bit = it->first[2];
		move_description[it->first][0] = extractBits(move, first_bit, last_bit);
    }

    // For testing 
    print(move_description["origin"][0]);
    print(move_description["o_piece"][0]);
    print(move_description["destination"][0]);
    print(move_description["d_piece"][0]);
    print(move_description["promotion"][0]);

}
