/* Professor Scott, main.cpp
9/21/2021

Client to test student base class and inheritance in the undergraduate class

*/

#include "student.h"    // include base class header file
#include "undergrad.h"  // include undergrad header file

#include <iostream>
using namespace std;

int main() {

  Student stu;        // NOTE: nothing stops us from instantiating a base class
  Undergrad underg;   // undergraduate, a derived class

  cout << stu.getName() << endl;   // get the name of the student
  underg.print();   // print the undergrad info

}
