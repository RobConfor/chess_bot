#include <iostream>

enum Value {
    EMPTY = 0, //empty square
    PAWN = 1,
    KNIGHT = 3,
    //technically these are equal value but changed for syntax reasons
    //might need to come up with better solution later on
    BISHOP = 4,
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
    Piece(){
        //random color but not random
        this->value = EMPTY;
        this->color = BLACK;
    }

    //pawn
    Piece(Color color){
        this->value = PAWN;
        this->color = color;
    }

    Piece(Value name, Color color){
        this->value = name;
        this->color = color;
    }

    //getter
    Value get_value(){
        return this->value;
    }

    //getter
    Color get_color(){
        return this->color;
    }

    private:
    Value value;
    Color color;
};

std::ostream &operator<<(std::ostream &os, Piece &piece){
    char name; 
    Value value = piece.get_value();

    if(value == PAWN){
        name = 'P';
    }
    if(value == KNIGHT){
        name = 'N';
    }
    if(value == BISHOP){
        name = 'B';
    }
    if(value == KING){
        name = 'K';
    }
    if(value == QUEEN){
        name = 'Q';
    }
    if(value == ROOK){
        name = 'R';
    }
    if(value == EMPTY){
        name = '-';
    }

    os << name;

    return os;
}


