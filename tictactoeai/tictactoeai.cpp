#include <iostream>
#include "board.h"
#include "player.h"
#include "artint.h"
using namespace std;

int main() {
  // game pieces
  Board* board = new Board();
  Player* player = new Player(true);
  ArtInt* artint = new ArtInt(false);
  string valid = "";

  // Main game loop
  for(int i = 0; i < 9 && board.checkWin() == 0; i++) {
    invalid = true; // guilty until proven innocent
    while(invalid) {
      board->draw();
      cout << valid << endl; // prints prev turn or error
      int position;
      bool is_player;

      // choose x or o and have them take their turn
      if(i % 2 == 0) {
        if(player->is_x()) {
          position = player->doTurn();
          is_player = true;
        } else {
          position = artint->doTurn(board);
          is_player = false;
        }
      } else {
        if(player->is_x()) {
          position = artint->doTurn(board);
          is_player = false;
        } else {
          position = artint->doTurn();
          is_player = true;
        }
      }

      // try to place and return error if failed
      if(is_player) {
        valid = board->place(player->is_x(), position); // player's turn
      } else {
        valid = board->place(artint->is_x(), position); // ai's turn
      }
      if(valid[0] == 'P') invalid = true; // guilty
      else invalid = false; // innocent
    }
  }
  return 0;
}
