#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"

class Player {
private:
  bool piece;
  int size;
public:
  Player(bool);
  bool is_x();
  int doTurn();
};

#endif
