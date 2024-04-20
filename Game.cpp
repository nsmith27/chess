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


void Game::movePiece(std::string user_move){
	// split the string
	// look up first coordinate
	// look up second coordinate
	// create stack move
	// execute stack move

	addNewMoveToHistory();
}

void Game::executeBitMove(const uint32_t stack_move){
	interpretBitMove(stack_move);
	//move_description
}


void Game::addNewMoveToHistory(){

}

void Game::interpretBitMove(const uint32_t stack_move) {
    for (auto it = move_description.begin(); it != move_description.end();
         ++it) {
        uint8_t val = it->first[0];
        uint8_t first_bit = it->first[1];
        uint8_t last_bit = it->first[2];
        move_description[it->first][0] = extractBits(stack_move, first_bit, last_bit);
    }
}

uint8_t Game::extractBits(const uint32_t num, const int first_bit,
                          const int last_bit) {
    uint32_t mask = (1u << (last_bit - first_bit + 1)) - 1;
    return (num >> first_bit) & mask;
}

void Game::undoLastMovefromHistory(){

}

