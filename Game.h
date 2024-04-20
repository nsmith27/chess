#pragma once

#include <list>
#include <string>
#include <vector>

#include "Board.h"
#include "Piece.h"

class Game {
    // Uses intermediate notation that can do and undo moves.
    // Keeps track of the pieces and game state.
    // Types of moves:
    // - user_move  = string notation from user input (ex: e2-e4)
    // - inter_move = string notation that explains fuller context of move
    //   (ex: e2-e4)
    // - stack_move = bit notation for recoding on the move stack
    // - pgn_move  = string notation from user input in pgn format
   private:
    std::list<Piece*> white_pieces;
    std::list<Piece*> black_pieces;
    std::vector<uint32_t> move_stack;

    uint8_t extractBits(uint32_t number, int start, int end);

   public:
    Board board;
    Game();

    void movePiece(std::string user_move);
    void executeBitMove(const uint32_t stack_move);
    void addNewMoveToHistory();
    void interpretBitMove(const uint32_t stack_move);
    void undoLastMovefromHistory();
    std::map<std::string, std::vector<uint8_t>> move_description;
};
