#include "Piece.hpp"



//base will be a pawn
Piece::Piece(Rank rank){
    value = PAWN;
    this->rank = rank;
}

Piece::Piece(Value name, Rank rank){
   value = name;
   this->rank = rank;
}


