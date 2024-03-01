#ifndef PIECE_HPP
#define PIECE_HPP

#include <string>

enum Value {
    PAWN = 1,
    KNIGHT = 3,
    BISHOP = 3,
    ROOK = 5,
    QUEEN = 9,
    KING = 500,
};

enum Rank {
   WHITE = 1,
   BLACK = 0,
};

class Piece {
    public:

    //base will be a pawn
    Piece(Rank rank);

    Piece(Value name, Rank rank);

    private:
    Value value;
    Rank rank;

};






#endif