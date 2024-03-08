enum Value {
    EMPTY = 0, //empty square
    PAWN = 1,
    KNIGHT = 3,
    //technically these are equal value but changed for syntax reasons
    //might need to come up with better solution later on
    BISHOP = 4,
    ROOK = 5,
    QUEEN = 9,
    KING = 500,
};

enum Color {
    BLACK = 0,
    WHITE = 1,
};

class Piece {
    public:

    //empty square
    Piece(){
        //random color but not random
        this->value = EMPTY;
        this->color = BLACK;
    }

    //pawn
    Piece(Color color){
        this->value = PAWN;
        this->color = color;
    }

    Piece(Value name, Color color){

        this->value = name;
        this->color = color;

        if(this->value == BISHOP || this->value == QUEEN || this->value == ROOK){
            this->is_infinte = true;
        } else {
            this->is_infinte = false;
        }
    }

    //getter
    Value get_value(){
        return this->value;
    }

    //getter
    Color get_color(){
        return this->color;
    }


    //might make a function or that describes a peices movement
    //this is in the 8x8 matrix of the board (but it is an array) 
        //white pawn = -8
        //black pawn = +8
            //capture white = -7 -9 
            //capture black = +7 +9
        //bishop = +7 -7 or -9 +9 (infinetly along that diagonal)
        //rook = +1 -1 or +8 -8 (infinetly along diagonal)
        //knight = +15 -15 or +17 -17 or +6 -6 or +10 -10
        //queen  +-8 +-7 +-9 +-1 (infinite)
        //king +-8 +-7 +-9 +-1 (once)
    

    private:
    Value value;
    Color color;
    bool is_infinite; //tells us if piece can move ifintily (queen, rook, bishop)
};

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
    if(value == EMPTY){
        name = '-';
    }

    os << name;

    return os;
}


