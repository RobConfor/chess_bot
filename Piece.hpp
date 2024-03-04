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
    BLACK = 0,
    WHITE = 1,
};

class Piece {
    public:
    
    //pawn
    Piece(Rank rank);

    Piece(Value name, Rank rank);


    private:
    Value value;
    Rank rank;

};






#endif