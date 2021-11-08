/* Professor Scott, student.cpp
9/21/2021

Implementation of the base class functions.  Note nothing is special about this class
so we can instantiate a copy if we like without a problem (and do in our main.cpp).

If we want to disallow instantiating a class we include at least one "pure virtual"
function.  We'll cover this more in detail next Monday

*/

#include "student.h"
#include <iostream>

using namespace std;

// constructor for student class
Student::Student(string N, string SS) {

  Name = N;
  SSNum = SS;
  cout << "base class constructor!!" << endl;

}

// set the student name
void Student::setName(const string val) {

  Name = val;

}
  
// set the social security number
void Student::setSSNum(const string val) {

  SSNum = val;

};

// get the student name
string Student::getName() {

  return (Name);

}

// get the social security number
string Student::getSSNum() {
  
  return (SSNum);

}
