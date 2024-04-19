#pragma once

#include "Game.h"

#include <iostream>

#include "Board.h"
#include "printer.h"

Game::Game() {
    move_description = {
        {"origin", {0, 0, 5}},        {"o_piece", {0, 6, 9}},
        {"destination", {0, 10, 15}}, {"d_piece", {0, 16, 19}},
        {"promotion", {0, 20, 23}},
    };
}

uint8_t Game::extractBits(const uint32_t move, const int first_bit,
                          const int last_bit) {
    uint32_t mask = (1u << (last_bit - first_bit + 1)) - 1;
    return (move >> first_bit) & mask;
}

void Game::interpretMove(const uint32_t move) {
    for (auto it = move_description.begin(); it != move_description.end();
         ++it) {
        uint8_t val = it->first[0];
        uint8_t first_bit = it->first[1];
        uint8_t last_bit = it->first[2];
        move_description[it->first][0] = extractBits(move, first_bit, last_bit);
    }
}

void Game::undoLastMovefromHistory(){

}

void Game::addNewMoveToHistory(){

}

