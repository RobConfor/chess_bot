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

    //is taking a piece
    //I dont think takes matters, only reason it does is we can keep track of which peices are deleted 
    //since when we pet a peice to a new position, it automatically removes the previously placed piece
    if(pos.find('x') != std::string::npos){
        takes = true;
    } else {
        takes = false;
    }

    
    if(islower(pos[0])){
        //we know it is a pawn move
        value = 1;

        //nested yes ik yuck
        if(takes == false){

            //this is not correct
            //stoi removes all letters and leaves just numbers
            return stoi(pos);
        }

        return ;

    }

    //checks other pieces
    for(int i = 0; i < 4; ++i){
        if(pos[0] == PIECE_NAMES[i]){
            
        }
    }

    //this just changes sytnax since position will be in different place in string array
    if(takes){
        //we want pos[2] and pos[3]


    } else {
        //we want pos[1] and pos[2]
        

    }


    return ;
}


int string_to_pos(std::string){

    return ;
}

const char PIECE_NAMES[] = {
  'N',   // Knight
  'B', // Bishop
  'R',  // Rook
  'Q'  // Queen
};
