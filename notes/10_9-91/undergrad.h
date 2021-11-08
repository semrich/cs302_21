/* Professor Scott, undergrad.h
9/21/2021

This is the interface for a undergraduate derived class.  Note that the most special
thing about this example is the notation indicating inheritance.  There are other
types of inheritance besides public but we will not cover them this semester.

*/
#ifndef UNDERGRAD_H
#define UNDERGRAD_H

#include "student.h" // we need to include the base class header, but not CPP
#include <string>   // we'll use strings in this example

// Derived Undergrad class; inherits from Student
class Undergrad : public Student {

 public:

  Undergrad();   // constructor
  void print();  // print function

 private:

  int LivesonCampus;   // data unique (maybe) to an undergrad relative to, say,
                       // a high school or graduate student

};

#endif
