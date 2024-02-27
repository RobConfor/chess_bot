#ifndef PIECE_HPP
#define PIECE_HPP

#include <string>

class Piece {
    public:

    //base will be a pawn
    Piece();

    Piece(Value name);

    private:
    Value value;

};


enum Value {
    PAWN = 1,
    KNIGHT = 3,
    BISHOP = 3,
    ROOK = 5,
    QUEEN = 9,
    KING = 500,
};


#endif