#pragma once

#include <list>
#include <string>
#include <vector>

#include "Board.h"
#include "Piece.h"

class Game {
    // Uses intermediate notation that can do and undo moves.
    // Keeps track of the pieces and game state.  
   private:
    std::list<Piece*> white_pieces;
    std::list<Piece*> black_pieces;
    std::vector<uint32_t> move_stack;

    uint8_t extractBits(uint32_t number, int start, int end);

   public:
    Board board;
    Game();

    void undoLastMovefromHistory();
    void addNewMoveToHistory();
    void interpretMove(const uint32_t move);
    std::map<std::string, std::vector<uint8_t>> move_description;
};
