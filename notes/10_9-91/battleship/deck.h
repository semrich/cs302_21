#ifndef DECK_H
#define DECK_H

#include "piece.h"   // base class header

class Deck : public Piece {
  
 public:
  Deck();                       // deck constructor
  void setType(char);           // set ship type
  virtual void print();         // display the type of ship
 private:
  char ship_type;            // type of ship
  
};

#endif
