#ifndef ARTINT_H
#define ARTINT_H

#include "board.h"

class ArtInt {
private:
  bool piece;
  int getBestMove(Board*, bool);
public:
  ArtInt(bool);
  bool is_x();
  int doTurn(Board*);
};

#endif
