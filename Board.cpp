#include "Board.hpp"

    //initializes basic board with all pieces on starting squares
    //we will assume we are playing 
Board::Board(){

}

    //can make a particular initilizer that can set up chess puzzles
    //takes in peice placesment as an array
    

    //REQUIRES: move is given in chess notation
    //REQUIRES: peice moves in its correct pathing
    //also takes peice if required
void Board::move_peice(std::string move){

}



//EFFECT: takes in chess notation as imput and returns a position in array
int notation_to_position(std::string pos, bool &takes, int &value){
    //capital letters mean peice
    //lower case is a pawn
    value  = stoi(pos.begin());


    //x means takes

    return 
}

