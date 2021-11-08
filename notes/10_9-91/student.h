/* Professor Scott, student.h
9/21/2021

This is the interface for a student base class.  Note that nothing is special about this
class other than the data are declared as "protected" and not "private."  Protected
is an intermediate level of access that allows classes that inherit from this class
to access data (sort of like friendship, but not really) but not the client/main
function.

Good style, according to what we do based on the text, is to make the data of a 
base class private and use get/set functions as needed.  More in class today

*/

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {   // base class for a student

 public:

  Student(string ="empty", string = "empty");  // constructor
  
  void setName(const string);   // set functions
  void setSSNum(const string);
    
  string getName();   // get functions
  string getSSNum();

 protected:  // NOTE:  we make our data protected, not private, so inherited
             // classes can access them directly

  string Name;
  string SSNum;

};

#endif
