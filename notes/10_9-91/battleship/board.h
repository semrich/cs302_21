#ifndef BOARD_H
#define BOARD_H

#include <vector>      // used for STL vectors
#include "piece.h"     // used for our class that will compose the generic piece

class Board{

 public:

  Board();                                            // constructor
  bool place_ship(char, int, int, int, char, bool);   // places a ship
  void place_random(char, int);                       // place a ship random
  void randomStart();                                 // generate ships randomly

  bool fire(char, int, bool);    // fire at a ship location 

  bool amKaput();                // true if and only if all ships sunk

  void printMine();              // print my board
  void printEnemy();             // print my enemies board (hide ship locations)
  void printStats();             // print statistics of the games
  bool wasTested(char, int);     // determines if a specific piece was tested
  
 private:
  int boardSize;               // size of board
  int placedShips;             // total number of ships
  int numHits;                 // number of hits
  int numMisses;               // number of misses
  std::vector<std::vector<Piece*> > pieces;     // 2X2 grid of piece pointers

};

#endif
