#ifndef BOARD_H
#define BOARD_H

#include <string>
using namespace std;

class Board {
private:
  int* pieces;
  int size;
public:
  Board();
  void draw();
  string place(bool is_player_x, int position);
  int checkWin();
  Board* copyBoard();
  int getSize();
  int getPiece(int position);
};

#endif
