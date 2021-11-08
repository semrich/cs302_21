#include <iostream>     // i/o functions
#include <ctime>        // random number functions
#include <cstdlib>
#include "board.h"      // our class, based on inheritance

using namespace std;

int main () {

  Board my_board;    // board object

  srand(time(NULL));   // seed random number generator

  // randomize the location of the ships
  my_board.randomStart();

  // loop until all ships are sunk
  while (! my_board.amKaput() ) {

    char col = rand() % 10 + 'A';    // pick a random column
    int  row = rand() % 10 + 1;      // pict a random row

    if (! my_board.wasTested (col, row)) {

      // fire at the random location
      cout << "Firing at " << col << " " << row << " ..." << endl;
      my_board.fire(col, row, true);

      // print stats and the board
      my_board.printStats();
      my_board.printMine();

    }

  }

}
