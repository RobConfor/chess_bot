#include <cstdlib>
#include <string>
#include <iostream>
#include "Piece.hpp"
#include "Board.hpp"
#include "Board.cpp"
#include "Piece.cpp"

using namespace std;

int main() {
    cout << "Hello World" << endl;

    Board game = new Board();

    cout << game.to_string();

    return 0;
}