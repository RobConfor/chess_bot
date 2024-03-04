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


