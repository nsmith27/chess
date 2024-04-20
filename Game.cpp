#pragma once

#include "Game.h"

#include <iostream>
#include <sstream>
#include <vector>

#include "Board.h"
#include "printer.h"

Game::Game() {
    move_description = {
        {"origin", {0, 0, 5}},        {"o_piece", {0, 6, 9}},
        {"destination", {0, 10, 15}}, {"d_piece", {0, 16, 19}},
        {"promotion", {0, 20, 23}},
    };
}

void Game::movePiece(std::string user_move) {
    // split the string
    std::vector<std::string> coords = split(user_move, '-');
    // look up first coordinate
    uint8_t origin = board.getCoordinateFromMove(coords[0]);
    uint8_t o_piece = board.getPiece(coords[0]);
    // look up second coordinate
    uint8_t dest = board.getCoordinateFromMove(coords[1]);
    uint8_t d_piece = board.getPiece(coords[1]);
    // create stack move
    // execute stack move
	// temporary plan to move piece
	print(coords[0], coords[1]);
	printInt(origin, o_piece, dest, d_piece);
	printBinary(origin);
	printBinary(o_piece);
	printBinary(dest);
	printBinary(d_piece);
	std::cout << std::endl;
	board.setPiece(dest, 2);
	board.setPiece(origin, board.piece_to_val['-']);
    // addNewMoveToHistory();
}

std::vector<std::string> Game::split(const std::string& str, char delim) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delim)) {
        tokens.push_back(token);
    }
    return tokens;
}

void Game::executeBitMove(const uint32_t stack_move) {
    interpretBitMove(stack_move);
    // move_description
}

void Game::addNewMoveToHistory() {}

void Game::interpretBitMove(const uint32_t stack_move) {
    for (auto it = move_description.begin(); it != move_description.end();
         ++it) {
        uint8_t val = it->first[0];
        uint8_t first_bit = it->first[1];
        uint8_t last_bit = it->first[2];
        move_description[it->first][0] =
            board.extractBits(stack_move, first_bit, last_bit);
    }
}

void Game::undoLastMovefromHistory() {}
