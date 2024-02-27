#include "Board.hpp"

    //initializes basic board with all pieces on starting squares
    //we will assume we are playing 
Board::Board(){

}


//a particular initilizer that can set up chess puzzles
//takes in peice placesment as an array in chess notation
Board::Board(std::string piece[]){

}
    

//REQUIRES: move is given in chess notation
//REQUIRES: peice moves in its correct pathing
//also takes peice if required
void Board::move_peice(std::string move){

}



//EFFECT: takes in chess notation as imput and returns a position in array
//capital letters denotes a peice
    //lower case is a pawn
    //example notaitons: (case sensitive)
    //  e4 pawn
    //  Bg2 bishop
    //  Nf3 knight 
    //  Kxe3 king takes pawn (we have to dedce which king, but we can if we know if its white or black turn)
    //  Qd5+ queen checks king
int notation_converter(std::string pos, bool &takes, int &value){
    
    //removes all letter and only leaves number which is final position
    int end_pos = stoi(pos);


    return ; 
}

//I j copy pasted ts idk why it got so many const declarations like bro we get it we cant change u
constexpr const char *const PIECE_NAMES[] = {
  "N",   // Knight
  "B", // Bishop
  "R",  // Rook
  "Q",  // Queen
  "K",   // King
};
