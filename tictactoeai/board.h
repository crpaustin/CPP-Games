#ifndef BOARD_H
#define BOARD_H

#include <string>
using namespace std;

class Board {
private:
  int* pieces;
  void draw();
public:
  Board();
  string place(bool is_player_x, int position);
  bool checkWin();
  Board* copyBoard();
};

#endif
