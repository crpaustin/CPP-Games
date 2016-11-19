#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"
#include "artint.h"

class Game {
private:
  static int game_loop(Board*, Player*, ArtInt*);
  static int game_loop(Board*, ArtInt*, ArtInt*);
public:
  static void run();
};

#endif
