#ifndef PIECE_H
#define PIECE_H

class Piece{
  
 public:
  Piece(char);
  char whichType();
  bool tested();
  void bomb();
  virtual void print() = 0;
 private:
  char piece_type;
  bool piece_state;
  
};

#endif
