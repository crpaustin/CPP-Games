#ifndef PLAYER_H
#define PLAYER_H

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
