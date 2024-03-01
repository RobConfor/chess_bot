#include "Board.hpp"

    //initializes basic board with all pieces on starting squares
    //we will assume we are playing 
Board::Board(){

    //probaably a better way to do this but im lazy
    Piece b_rook1 = Piece(ROOK, BLACK);
    Piece b_bishop1 = Piece(BISHOP, BLACK);
    Piece b_knight1 = Piece(KNIGHT, BLACK);
    Piece b_rook2 = Piece(ROOK, BLACK);
    Piece b_bishop2 = Piece(BISHOP, BLACK);
    Piece b_knight2 = Piece(KNIGHT, BLACK);

    Piece b_queen = Piece(QUEEN, BLACK);
    Piece b_king = Piece(KING, BLACK);
    
    board[0] = b_rook1;
    board[1] = b_knight1;
    board[2] = b_bishop1; 
    board[3] = b_queen;
    board[4] = b_king;
    board[5] = b_bishop2;
    board[6] = b_knight2;
    board[7] = b_rook2;

    for(int i = 8; i < 16; ++i){
        Piece pawn = Piece(BLACK);
        board[i] = pawn;
    }

    for(int i = 47; i < 56; ++i){
        Piece pawn = Piece(WHITE);
        board[i] = pawn;
    }

    Piece w_rook1 = Piece(ROOK, WHITE);
    Piece w_bishop1 = Piece(BISHOP, WHITE);
    Piece w_knight1 = Piece(KNIGHT, WHITE);
    Piece w_rook2 = Piece(ROOK, WHITE);
    Piece w_bishop2 = Piece(BISHOP, WHITE);
    Piece w_knight2 = Piece(KNIGHT, WHITE);

    Piece w_queen = Piece(QUEEN, WHITE);
    Piece w_king = Piece(KING, WHITE);

    board[56] = w_rook1;
    board[57] = w_knight1;
    board[58] = w_bishop1; 
    board[59] = w_queen;
    board[60] = w_king;
    board[61] = w_bishop2;
    board[62] = w_knight2;
    board[63] = w_rook2;
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
        value = PAWN;

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
            value = PIECE_NAMES[i];
            
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
