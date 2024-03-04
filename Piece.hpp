#ifndef PIECE_HPP
#define PIECE_HPP

#include <string>

enum Value {
    EMPTY = 0, //empty square
    PAWN = 1,
    KNIGHT = 3,
    BISHOP = 3,
    ROOK = 5,
    QUEEN = 9,
    KING = 500,
};

enum Color {
    BLACK = 0,
    WHITE = 1,
};

class Piece {
    public:

    //empty square
    Piece();

    //pawn
    Piece(Color color);

    Piece(Value name, Color color);

    Value get_value();

    Color get_color();

    private:
    Value value;
    Color color;

};



#endif