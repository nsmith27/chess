#ifndef GAME_H
#define GAME_H

#include <list>
#include <vector>
#include <string>


#include "Board.h"
#include "Piece.h"

class Game {
   private:
    Board game_board;
    std::list<Piece*> white_pieces;
    std::list<Piece*> black_pieces;
    std::vector<uint32_t> move_stack;
    std::map<std::string, std::vector<uint8_t>> move_description;

    uint8_t extractBits(uint32_t number, int start, int end);

   public:
    Game();
    
    void getMove(const uint32_t move);

};

#endif  // GAME_H
