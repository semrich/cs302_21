#ifndef WATER_H
#define WATER_H

#include "piece.h"     // include header of the base class

class Water : public Piece {    // public inheritance
  
 public:
  Water();                   // constructor
  virtual void print();      // display piece
  
};

#endif
