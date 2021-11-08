#include <iostream>
#include "piece.h"  // base class header
#include "deck.h"   // derived class header

// Deck constructor
Deck::Deck() : Piece('d') { }

// set ship type
void Deck::setType(char type) {

  ship_type = type;

}

// print either a "*" if hit (as this is a ship) or the ship type
void Deck::print() {

  if (Piece::tested() == 1)
    std::cout << "*";
  else
    std::cout << ship_type;

}
