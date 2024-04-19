#pragma once

#include <iostream>
#include <string>

namespace ChessColor {
enum Color { WHITE, BLACK };
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// Virtual Piece class
class Piece {
   public:
    virtual void move() = 0;
};

//////////////////////////////////////////////////////////////////////////////////////////////////
// Pawn class
class Pawn : public Piece {
   public:
    Pawn(ChessColor::Color pieceColor) : color(pieceColor) {}

    void move() override { std::cout << "Pawn moved" << std::endl; }

   private:
    ChessColor::Color color;
};

//////////////////////////////////////////////////////////////////////////////////////////////////
// Knight class
class Knight : public Piece {
   public:
    Knight(ChessColor::Color pieceColor) : color(pieceColor) {}

    void move() override { std::cout << "Knight moved" << std::endl; }

   private:
    ChessColor::Color color;
};

//////////////////////////////////////////////////////////////////////////////////////////////////
// Bishop class
class Bishop : public Piece {
   public:
    Bishop(ChessColor::Color pieceColor) : color(pieceColor) {}

    void move() override { std::cout << "Bishop moved" << std::endl; }

   private:
    ChessColor::Color color;
};

//////////////////////////////////////////////////////////////////////////////////////////////////
// Rook class
class Rook : public Piece {
   public:
    Rook(ChessColor::Color pieceColor) : color(pieceColor) {}

    void move() override { std::cout << "Rook moved" << std::endl; }

   private:
    ChessColor::Color color;
};

//////////////////////////////////////////////////////////////////////////////////////////////////
// Queen class
class Queen : public Piece {
   public:
    Queen(ChessColor::Color pieceColor) : color(pieceColor) {}

    void move() override { std::cout << "Queen moved" << std::endl; }

   private:
    ChessColor::Color color;
};

//////////////////////////////////////////////////////////////////////////////////////////////////
// King class
class King : public Piece {
   public:
    King(ChessColor::Color pieceColor) : color(pieceColor) {}

    void move() override { std::cout << "King moved" << std::endl; }

   private:
    ChessColor::Color color;
};

#pragma once
