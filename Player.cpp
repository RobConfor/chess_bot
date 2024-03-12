

//player will be the base class 
class Player {
    //bascially going to be the same thing as a bot, except controlled by a human rather than the ai abiovusly

public:

    Player() virtual = 0;

    //main decision making function
    //might need return type. to be thought about later
    void play_turn() virtual = 0;

    //tells us how a piece moves, or what squares a piece can move to
    //idk return type but maybe it is int[] of positions it can move to
    void piece_movement(Piece piece) virtual = 0;

    //should tell us how threatened a piece is 
    //we can have a depth counter, which tells us maybe how many moves until this peice is threatened
    //we can also use a counter to tell us how important it is for us to defend this peice (aka if defended or low val like pawn)
    int is_attacked() virtual = 0;

    //do we need a neural network???? this seems like its going to be a lot of math
    //counts number of defenders of a piece, probably called in is_attacked
    //also counts value of defenders, as they might be weak defenders (queen)
    int is_defended() virtual = 0;

    //tells us if king is (or is going to be) in check (ie after we make a move)
    //pins can be found with this
    bool is_in_check() virtual = 0;

    //might be immplemnted in piece class idk which makes more sense
    //this will basically j tell us if there is a peice on the square
    bool can_move() virtual = 0;

private:
Color color;


};



class HumanPlayer : public Player {

    public:
    HumanPlayer();

    //main decision making function
    //might need return type. to be thought about later
    void play_turn() override;

    //tells us how a piece moves, or what squares a piece can move to
    //idk return type but maybe it is int[] of positions it can move to
    void piece_movement(Piece piece) override;

    //should tell us how threatened a piece is 
    //we can have a depth counter, which tells us maybe how many moves until this peice is threatened
    //we can also use a counter to tell us how important it is for us to defend this peice (aka if defended or low val like pawn)
    int is_attacked() override;

    //do we need a neural network???? this seems like its going to be a lot of math
    //counts number of defenders of a piece, probably called in is_attacked
    //also counts value of defenders, as they might be weak defenders (queen)
    int is_defended() override;

    //tells us if king is (or is going to be) in check (ie after we make a move)
    //pins can be found with this
    bool is_in_check() override;

    //might be immplemnted in piece class idk which makes more sense
    //this will basically j tell us if there is a peice on the square
    bool can_move() override;

private:
Color color;


};



class Bot : public Player {
public:

    Bot(Color color){
        //if white or black
        this->color = color;

        Value order[8] = {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK};

        for(int i = 0; i < 16; ++i){

            if(i < 8){
                this->my_pieces.push_back(Piece(order[i], color));
            } else {
                this->my_pieces.push_back(Piece(color));
            }
            cout << my_pieces.at(i) << endl;
            
        }

    }

    //for puzzles
    Bot(string pieces[], int length, int start);

    //main decision making function
    //might need return type. to be thought about later
    void play_turn() override;

    //tells us how a piece moves, or what squares a piece can move to
    //idk return type but maybe it is int[] of positions it can move to
    void piece_movement(Piece piece) override;

    //should tell us how threatened a piece is 
    //we can have a depth counter, which tells us maybe how many moves until this peice is threatened
    //we can also use a counter to tell us how important it is for us to defend this peice (aka if defended or low val like pawn)
    int is_attacked() override;

    //do we need a neural network???? this seems like its going to be a lot of math
    //counts number of defenders of a piece, probably called in is_attacked
    //also counts value of defenders, as they might be weak defenders (queen)
    int is_defended() override;

    //tells us if king is (or is going to be) in check (ie after we make a move)
    //pins can be found with this
    bool is_in_check() override;

    //might be immplemnted in piece class idk which makes more sense
    //this will basically j tell us if there is a peice on the square
    bool can_move() override;

    //do we need function that check for forks and other tactics?


private:
//idk what member variables it should have
vector<Piece> my_pieces;
Color color;

};