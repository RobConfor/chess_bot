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

    for(int i = 16; i < 47; ++i){
        Piece empty_square = Piece();
        board[i] = empty_square;
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

    this->turn = 0;
}


//a particular initilizer that can set up chess puzzles
//takes in peice placesment as an array in chess notation
//idk how to tell if it is a black peice or white
Board::Board(std::string piece[], int length, int start){

    for(int i = 0; i < BOARD_SIZE; ++i){
        Piece empty_square = Piece();
        board[i] = empty_square;
    }

    //turn tells if it is white or black turn
    turn = start;

    for(int i = 0; i < length; ++i){
        
        //this is stupid and doesnt work but also idk how to know if peice r white or black
        //we could do alternatig but only works if there is even # of colors
        Value v = PAWN;
        bool take = false;
        int l = notation_converter(piece[i], take, v);

        Piece temp = Piece(v, WHITE); 

        board[string_to_pos(piece[i])] = temp;
    }
}

//returns the peice at a spesific square in index notation
Piece Board::get_piece(int index){
    return this->board[index];
}

//returns peice in given chess notation pos
Piece Board::get_piece(std::string pos){
    return this->board[string_to_pos(pos)];
}


//REQUIRES: move is given in chess notation
//REQUIRES: peice moves in its correct pathing
//also takes peice if required
void Board::move_peice(std::string move){

    //not done yet
    bool takes = false;
    Value piece = PAWN;

    int pos = notation_converter(move, takes, piece);

    if(takes == true){
        take_peice(move);
    }

    turn++;
}


//REQUIES: pos is the pos of peice being taken
//adds deleted peice to the taken vector
void Board::take_peice(string pos){
    taken.push_back(this->board[string_to_pos(pos)]);
}

const char PIECE_NAMES[] = {
  'N',   // Knight
  'B', // Bishop
  'R',  // Rook
  'Q'  // Queen
};

//EFFECT: takes in chess notation as imput and interprets it
//capital letters denotes a peice
    //lower case is a pawn
    //example notaitons: (case sensitive)
    //  e4 pawn
    //  Bg2 bishop
    //  Nf3 knight 
    //  Kxe3 king takes pawn (we have to dedce which king, but we can if we know if its white or black turn)
    //  Qd5+ queen checks king
int notation_converter(std::string pos, bool &takes, Value &value){

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

        if(takes == false){

            //this is not correct
            //stoi removes all letters and leaves just numbers
            return stoi(pos);
        }

        return ;

    }

    //have to checks other pieces

    //this just changes sytnax since position will be in different place in string array
    if(takes){
        //have to convert to string so we can add them (idk)
        //we want pos[2] and pos[3]
        std::string new_pos = std::to_string(pos[2]) + pos[3];
        return string_to_pos(new_pos);
    } else {
        //we want pos[1] and pos[2]
        std::string new_pos = std::to_string(pos[1]) + pos[2];
        return string_to_pos(new_pos);
    }

    
    return 0;
}

//prints the whole board hopefully
std::ostream &operator<<(std::ostream &os, Board &board){
    for(int i = 0; i < 64; ++i){
        os << board.get_piece(i) << " ";
        if(i % 8 == 0){
            os << '\n';
        }
    }
    return os;
}

Piece Board::find_peice(Color color, Value value){
    for(int i = 0; i < BOARD_SIZE; ++i){
        if(this->board[i].get_color() == color && this->board[i].get_value() == value){
            return this->board[i];
        }
    }

    //peice was not found so taken?
    return ;
}


//this just  gives values to grid positions by index
const char GRID_POS[] = {
  'a',  
  'b',
  'c',  
  'd',
  'e',
  'f',
  'g',
  'h'
};


//REQUIRES: input is in form of just the grid pos. 
//EX:
    // a8 = 0
    // b6 = 17
    // h1 = 63
// returns grid pos in board array
int string_to_pos(std::string pos){

    int row = 0;
    int col = 0;

    for(int i = 0; i < 8; ++i){
        if(GRID_POS[i] == pos[0]){
            col = i;
            break;
        }
    }

    //removes all char in process
    row = stoi(pos);

    //have to check this
    return abs(row - 8)* 8 + col;
}


