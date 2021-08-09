/*  Professor Scott, knight.cpp

Another simple toy example illustrating static variables/functions.  Anything
defined as static in a class is stored only once outside of the class.  For 
example, if you do the equivalent of sizeof you'll get zero for this example
because count is stored once elsewhere.

NOTE:  Static variables must be initialized outside of the class.  See
below for example.

*/

#include <iostream>
#include <string>
#include "knight.h"  // include class definition

using std::cout;
using std::endl;

// Knight must be initialized outside of the class
int Knight::count = 0;


Knight::Knight () {

  count++;   // increment number of knights when instantiated

}

void Knight::HolyHandGrenade () {
  
  cout << "ONE!  TWO!  FIVE!" << endl;   // output for successful raid

}

void Knight::RunAwayRunAway() {  

  cout << "Run away! Run away" << endl;  // maybe next time

}

void Knight::SurveyCave() {

  if (count < 5)             // five brave knights are needed for this quest...
    RunAwayRunAway();
  else
    HolyHandGrenade();

}

int Knight::getCount() {

  return (count);   // return static variable

}

int main () {

  // note:  you can call static functions that reference static variables
  // without having an instantiation as shown below

  cout << "current count = " << Knight::getCount() << endl;

  Knight Arthur;   // knight #1
  Knight John;    // knight #2

  Arthur.SurveyCave();   // start the quest!!

}
