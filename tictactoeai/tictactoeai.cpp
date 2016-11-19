#include <iostream>
#include "board.h"
#include "player.h"
#include "artint.h"
using namespace std;

int main() {
  Board* board = new Board();
  Player* player = new Player(true);
  ArtInt* artint = new ArtInt(false);
  return 0;
}
