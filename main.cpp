#include <cstdlib>
#include <string>
#include <iostream>
#include "Board.cpp"

using namespace std;

int main() {
    cout << "Hello World" << endl;

    Board* game = new Board();

    game->to_string();

    return 0;
}