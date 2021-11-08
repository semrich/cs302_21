#include <iostream>
#include "piece.h"     // base class header
#include "water.h"     // derived class header

// water constructor
Water::Water() : Piece('w') { }


// print either a "*" if hit (as this is a ship) or the ship type
void Water::print() {

  if (Piece::tested())
    std::cout << ".";
  else
    std::cout << "o";

}
