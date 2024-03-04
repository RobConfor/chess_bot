#ifndef BOARD_HPP
#define BOARD_HPP


#include "Piece.hpp"
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <array>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Board {
    public:
    //initializes basic board with all pieces on starting squares
    //we will assume we are playing 
    Board();

    //a particular initilizer that can set up chess puzzles
    //takes in piece placesment as an array in chess notation
    Board(string piece[], int length, int start);

    //returns the peice at a spesific square in index notation
    Piece get_piece(int index);

    //returns peice in given chess notation pos
    Piece get_piece(string pos);

    //find peice given color and type of piece
    Piece find_peice(Color Color, Value value);

    void take_peice(string pos);


    //REQUIRES: move is given in chess notation
    //REQUIRES: peice moves in its correct pathing
    //also takes peice if required
    void move_peice(string move);
    //we can get the object of piece by using the board array and getting the element 

    //prints whole board
    void to_string();

    private:
    array<Piece, 64> board;

    //tells us which peices are taken
    vector<Piece> taken;

    static const int BOARD_SIZE = 64;

    //counts whos turn it is (so we know if it is white or black)
    int turn;

};

//EFFECT: takes in chess notation as imput and returns a position in array
int notation_to_position(string pos, bool &takes, Value &value);

int string_to_pos(std::string);

#endif