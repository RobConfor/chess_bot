#include <string>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <array>
#include <string>
#include <vector>
#include <cmath>
#include "Board.cpp"
#include "Player.cpp"

using namespace std;

class Game {
    public:

    //creates a game
    Game(){
        this->board = Board();
        this->turn = 0;

        bot = new Bot();
        player = new Player();


    }


    void play_game(){
        bool white_in_checkmate = false;
        bool black_in_checkmate = false;

        board.to_string();

        return;

        while(true){

            white_turn(black_in_checkmate);

            if(black_in_checkmate){
                cout << "white wins" << endl;
                break;
            }

            turn++;

            black_turn(white_in_checkmate);

            if(white_in_checkmate){
                cout << "black wins" << endl;
                break;
            }

            turn++;

        }


    }

    void white_turn(bool& checkmate);

    void black_turn(bool& checkmate);


    private:
    Board board; //the board
    int turn; // the turn or round of game
    vector<string> moves; //remembers all moves played in chess notation
    Bot bot;
    Player player;

};

int main() {
    cout << "Hello World" << endl;
    cout << "Would you like to play white or black or random? (type w, b or r)" << endl;

    stirng input;
    cin << input;

    //all execution should happen in game class
    Game game = Game();

    game.play_game();

    return 0;
}