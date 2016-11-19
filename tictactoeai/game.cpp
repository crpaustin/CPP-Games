#include <iostream>
#include "game.h"
#include "board.h"
#include "player.h"
#include "artint.h"
using namespace std;

void Game::run() {
  // game board
  Board* board = new Board();

  // Allow user to pick between x, o, or watch ai
  int choice;
  cout << "(1) Play as X." << endl;
  cout << "(2) Play as O." << endl;
  cout << "(3) AI vs AI." << endl;
  cout << "Choice: ";
  cin >> choice;

  // Set up players
  int score;
  if(choice == 1) {
    Player* player = new Player(true);
    ArtInt* artint = new ArtInt(false);
    score = game_loop(board, player, artint);
  } else if(choice == 2) {
    Player* player = new Player(false);
    ArtInt* artint = new ArtInt(true);
    score = game_loop(board, player, artint);
  } else {
    ArtInt* player = new ArtInt(true);
    ArtInt* artint = new ArtInt(false);
    score = game_loop(board, player, artint);
  }

  // Print victory or draw
  if(score == 0) {
    cout << "It's a draw." << endl;
  } else if(score == 1) {
    cout << "X wins." << endl;
  } else if(score == 2) {
    cout << "O wins." << endl;
  }
}

int Game::game_loop(Board* board, Player* player, ArtInt* artint) {
  string valid = "";
  for(int i = 0; i < 9 && board->checkWin() == 0; i++) {
    bool invalid = true; // guilty until proven innocent
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
          position = player->doTurn();
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
  board->draw();
  // Win condition
  return board->checkWin();
}

int Game::game_loop(Board* board, ArtInt* player, ArtInt* artint) {
  string valid = "";
  for(int i = 0; i < 9 && board->checkWin() == 0; i++) {
    bool invalid = true; // guilty until proven innocent
    while(invalid) {
      board->draw();
      cout << valid << endl; // prints prev turn or error
      int position;
      bool is_player;

      // choose x or o and have them take their turn
      if(i % 2 == 0) {
        if(player->is_x()) {
          position = player->doTurn(board);
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
          position = player->doTurn(board);
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
  board->draw();
  // Win conditions
  return board->checkWin();
}
