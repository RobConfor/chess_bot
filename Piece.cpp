#include "Piece.hpp"



Piece::Piece(){
    //random color but not random
    this->value = EMPTY;
    this->color = BLACK;
}

//base will be a pawn
Piece::Piece(Color color){
    this->value = PAWN;
    this->color = color;
}

Piece::Piece(Value name, Color color){
   this->value = name;
   this->color = color;
}

Value Piece::get_value(){
    return this->value;
}

Color Piece::get_color(){
    return this->color;
}


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

    os << name;

    return os;
}


