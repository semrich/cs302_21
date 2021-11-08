#include <iostream>
#include "board.h"
#include "piece.h"    // base class
#include "water.h"    // water derived class
#include "deck.h"     // deck derived class

using namespace std;

/************************************************************************/

// Member Function:  amKamput
// Role:  Returns true if and only if all the ships are sunk

Board::Board() : pieces(11,11), boardSize(10) {

  for (int i = 1; i <= 10; i++) 

    for (int j = 1; j <= 10; j++) {

      Water * newWater = new Water;   // create new water object
      pieces[i][j] = newWater;        // link new object into grid

    }

  placedShips = numHits = numMisses = 0;  // initialize our variables
  
}

// end of function

/************************************************************************/

bool Board::place_ship(char col, int row, int orient, int size, char type, bool verbose) {

  int end;
  int val = toupper(col) - 'A' + 1;

  // check if piece is off of the board
  if ((val < 1 || val > boardSize) || (row < 1 || row > boardSize)) {

    if (verbose)
      cout << "Invalid spot.  Please reenter" << endl << endl;
    return (false);

  }

  // determine where last piece of deck will land
  if (orient == 0)
    end = row + size - 1;
  else 
    end = val + size - 1;

  // if the ship will fit on the deck
  if (end <= boardSize) {

    for (int i = 0; i < size; i++) {

      int hit = 0;
      if (orient == 0) {

	if (pieces[i + row][val]->whichType() == 'd')   // we hit another ship
	  hit++;
	
      }
      else {

	if (pieces[row][val + i]->whichType() == 'd')  // we hit another ship
	  hit++;
      
      }

      if (hit == 1) {    // display a message and return false, as this is an invalid spot

	if (verbose) 
	  cout << "Invalid spot.  This ship overlaps with a previous ship.  Please reenter" << endl << endl;

	return (false);

      }

    }
  
  }
  else {   // piece hangs off the edge of the board, return false

    if (verbose)
      cout <<" Invalid spot, piece will not fit.  Please reenter" << endl << endl;

    return (false);

  }

  // remove water and add deck pieces
  for (int i = 0; i < size; i++) {

    Deck * newDeck = new (Deck);
    newDeck->setType(type);

    if (orient == 0) {

      delete (pieces[i + row][val]);	
      pieces[i + row][val] = newDeck;   // link in deck

    }
    else {

      delete (pieces[row][val + i]);   
      pieces[row][val + i] = newDeck;  // link in deck
    
    }
  }

  placedShips += size;    //  increment number of deck spaces on grid
  return (true);          //  success!!!

}

/************************************************************************/

// Member Function:  place_random
// Role:  Places a ship at random on the grid

void Board::place_random(char type, int size) {

  bool res;   // if placement is a sucess or not
 
  do {

    char col = rand() % 10 + 'A';    // pick a column at random
    int row = rand() % 10 + 1;       // pick a row at random
    int orient = rand() % 2;         // pick an orientation
    
    res = place_ship(col, row, orient, size, type, false);    // attempt to place ship
    
  } while (res == false);

}

/************************************************************************/

// Member Function:  amKamput
// Role:  Returns true if and only if all the ships are sunk

void Board::randomStart() {

  place_random('C', 5);   // place carrier
  place_random('B', 4);   // place battleship
  place_random('R', 3);   // place cruiser
  place_random('S', 3);   // place submarine
  place_random('D', 2);   // place destroyer

}

// end of function

/************************************************************************/

// Member Function:  fire
// Role:  Try and fire at a given spot on the board, displaying messages if verbose is true

bool Board::fire (char col, int row, bool verbose) {

  int val = toupper(col) - 'A' + 1;   // convert column to a numeric location 1 .. BoardSize

  if (! pieces[row][val]->tested()) {     // not previously tested

    // if the type of the piece is water....
    if (pieces[row][val]->whichType() == 'w') {

      if (verbose)   // display message
	cout << "Miss..." << endl << endl;
      
      numMisses++;
    
    }
    else if (pieces[row][val]->whichType() == 'd') {   // type of the piece is a deck

      if (verbose)  {   // display message

	cout << "Hit!  Ship type: ";
	pieces[row][val]->print();
	cout << endl << endl;

      }
      numHits++; 

    }

    pieces[row][val]->bomb();    // bombs away!!!
    return (true);

  }

  cout << "Already tested!" << endl << endl;   // already tested space
  return (false);
  
}

// end of function

/************************************************************************/
 
// Member Function:  amKamput
// Role:  Returns true if and only if all the ships are sunk

bool Board::amKaput() {

  return (numHits == placedShips);      // check if all the ships sunk

}  

// end of function

/************************************************************************/

// Member Function:  printMine
// Role:  Displays a battleship board with the ship locations visible

void Board::printMine() {

  // output the top of the grid
  for (char val = 'A'; val < 'K'; val++) 
    cout << "=" << val;

  // for each row
  for (int i = 1; i <= boardSize; i++) {
   
    cout << "=" << endl << "|";

    // for each col
    for (int j = 1; j <= boardSize; j++) {

      pieces[i][j]->print();       // use print function
      cout << "|";            

    }

    cout << " " << i << endl;

    // output === line in the grid
    for (int j = 1; j <= boardSize; j++)
      cout << "==";

  }

  cout << endl;

}

// end of function

/************************************************************************/

// Member Function:  printEnemy
// Role:  Displays a battleship board with the ship locations hidden

void Board::printEnemy() {

  // output the top of the grid
  for (char val = 'A'; val < 'K'; val++) 
    cout << "=" << val;

  // for each row
  for (int i = 1; i <= boardSize; i++) {
   
    cout << "=" << endl << "|";

    // for each col
    for (int j = 1; j <= boardSize; j++) {

      if ( pieces[i][j]->tested())
	cout << pieces[i][j] << "|";
      else
	cout << "o|";

    }

    cout << " " << i << endl;

    // output === line in the grid
    for (int j = 1; j <= boardSize; j++)
      cout << "==";

  }

  cout << endl;

}

// end of function

/************************************************************************/

// Member Function:  printStats
// Role: Display some simple statistics

void Board::printStats() {

  cout << "Hits:  " << numHits << endl;
  cout << "Misses: " << numMisses << endl << endl;

}

// end of function

/************************************************************************/

// Member Function:  wasTested
// Role: Return true if and only if a spot on the grid has been tested

bool Board::wasTested(char col, int row) {

  int val = toupper(col) - 'A' + 1;

  return (pieces[row][val]->tested());

}

// end of function
  
