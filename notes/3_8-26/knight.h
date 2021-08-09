/*  Professor Scott, knight.h

Another simple toy example illustrating static variables/functions.  Anything
defined as static in a class is stored only once outside of the class.  For 
example, if you do the equivalent of sizeof you'll get zero for this example
because count is stored once elsewhere.

The idea of this class is to count how many objects are instanciated, which is 
the most common use of this in the context of projects, but you can imagine
other examples (and we did for a bit in class)

NOTE:  Static variables must be initialized outside of the class.  See
knight.cpp for the example

*/

#ifndef KNIGHT_H
#define KNIGHT_H

class Knight {

 public:

  Knight();                   // don our brave soldier with the latest, greatest fashion
  void HolyHandGrenade ();    // "First shalt thou take out the Holy Pin, then shalt...
                              // shalt thou count to three, no more, no less."                                            
  void RunAwayRunAway();      // sometimes obvious, sometimes not...
  void SurveyCave();          // aww, a cute rabbit!

  static int getCount();      // return how many knights are still standing...

 public:

  static int count;      // number of knights in the party

};

#endif
