#include "Board.cpp"


class Bot {
public:
    Bot(){
        this->board = Board();
    }

    //for puzzles
    Bot(string pieces[], int length, int start);

    //main decision making function
    //might need return type. to be thought about later
    void play_turn();

    //tells us how a piece moves, or what squares a piece can move to
    //idk return type but maybe it is int of positions it can move to
    void piece_movement(Piece piece);

    //should tell us how threatened a piece is 
    //we can have a depth counter, which tells us maybe how many moves until this peice is threatened
    //we can also use a counter to tell us how important it is for us to defend this peice (aka if defended or low val like pawn)
    int is_attacked();

    //do we need a neural network???? this seems like its going to be a lot of math
    //counts number of defenders of a piece, probably called in is_attacked
    //also counts value of defenders, as they might be weak defenders (queen)
    int is_defended();

    //tells us if king is (or is going to be) in check (ie after we make a move)
    //pins can be found with this
    bool is_in_check();

    //might be immplemnted in piece class idk which makes more sense
    //this will basically j tell us if there is a peice on the square
    bool can_move();

    //do we need function that check for forks and other tactics?

    


private:
    Board board;


};