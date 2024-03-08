#include <string>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <array>
#include <string>
#include <vector>
#include <cmath>
#include "Board.cpp"
#include "Bot.cpp"

using namespace std;

class game {
    public:

    game();


    void play_game();


    private:
    Board board;

}

int main() {
    cout << "Hello World" << endl;

    //all execution should happen in game class
    Game* game = new game();

    return 0;
}