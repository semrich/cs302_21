/* Professor Scott, undergrad.cpp
9/21/2021

This is the implementation for an undergraduate derived class.  
Note that nothing is special about this other than we must use member 
initialization list syntax in the undergrad constructor to initialize
the base class data

Good style, according to what we do based on the text, is to make the data of a 
base class private and use get/set functions as needed.  More in class today

*/

#include "student.h"     // include base class header
#include "undergrad.h"   // derived (this) class header
#include <string>
#include <iostream>

using namespace std;

// constructor for the undergraduate class
// NOTE:  we need to call the constructor of the base class using
// member initialization list syntax; otherwise, we will need to use
// set functions.  See text and notes for details.

Undergrad::Undergrad() : LivesonCampus(1), Student("John", "Badin") {

  Dorm = "Alumni";
  cout << "Derived class constructor!!" << endl;  // display message

}

// print function
void Undergrad::print() {

  cout << Name << "  " << Dorm; 

}
