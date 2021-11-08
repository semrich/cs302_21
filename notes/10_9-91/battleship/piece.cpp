#include <iostream>
#include "piece.h"     // base class header

// constructor
Piece::Piece (char type) : piece_type (type), piece_state(0) { };


// bomb this piece
void Piece::bomb() {

  piece_state = 1;

}


// return piece type
char Piece::whichType() {

  return (piece_type);

}


//return tested status of piece
bool Piece::tested() {

  return (piece_state);

}
