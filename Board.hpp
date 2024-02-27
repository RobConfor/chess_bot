#ifndef BOARD_HPP
#define BOARD_HPP


#include "Piece.hpp"
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <array>
#include <string>

using namespace std;

class Board {
public:



//initializes basic board with all pieces on starting squares
//we will assume we are playing 
Board();

//a particular initilizer that can set up chess puzzles
//takes in peice placesment as an array in chess notation
Board(string piece[]);

//REQUIRES: move is given in chess notation
//REQUIRES: peice moves in its correct pathing
//also takes peice if required
void move_peice(string move);
//we can get the object of peive by using the board array and getting the element 


private:
array<Piece, 64> board;

};

//EFFECT: takes in chess notation as imput and returns a position in array
int notation_to_position(string pos, bool &takes, Value &value);





#endif