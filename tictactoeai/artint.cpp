#include <iostream>
#include "artint.h"
#include "board.h"
using namespace std;

ArtInt::ArtInt(bool is_x) {
  piece = is_x;

}

bool ArtInt::is_x() {
  return piece;
}

int ArtInt::getBestMove(Board* board, bool is_turn) {
  // cout << "Doing ai turn..." << board->getSize() << endl;
  // cout << endl;
  // board->draw();
  // Base Case: One move left, return 10, 0, -10.
  if(board->checkWin() > 0) {
    int score = board->checkWin();
    if(score == 0) {
      return 0;
    } else if(score == 1) {
      return 10;
    } else if(score == 2) {
      return -10;
    }
  } else if(board->getSize() == 8) {
    bool placed = false;
    for(int i = 0; i < 9 && !placed; i++) {
      if(board->getPiece(i) == 0) {
        if(is_turn) board->place(piece, i);
        else board->place(!piece, i);
        placed = true;
      }
    }
    int score = board->checkWin();
    if(score == 0) {
      return 0;
    } else if(score == 1) {
      return 10;
    } else if(score == 2) {
      return -10;
    }
  } else {
    // keep track of best move scores
    int scores[9];
    // for each possible move, calculate best possible move scores
    for(int i = 0; i < 9; i++) {
      if(board->getPiece(i) == 0) {
        Board* new_board = board->copyBoard();
        if(is_turn) new_board->place(piece, i);
        else new_board->place(!piece, i);
        scores[i] = getBestMove(new_board, !is_turn);
      } else {
        scores[i] = -15;
      }
    }
    // get first non-empty square index
    int index = 0;
    while(scores[index] < -10) index++;
    // consider x's turn and o's turn
    if((piece && is_turn) || (!piece && !is_turn)) {
      int max = index++; // make it the starting max
      for(int i = index; i < 9; i++) {
        if(scores[i] >= scores[max]) {
          max = i;
        }
      }
      return scores[max];
    } else {
      int min = index++;
      for(int i = index; i < 9; i++) {
        if(scores[i] > -15 && scores[i] <= scores[min]) {
          min = i;
        }
      }
      return scores[min];
    }
  }
}

int ArtInt::doTurn(Board* board) {
  // Empty board, pick top left
  if(board->getSize() == 0) return 0;
  // keep track of best move scores
  int scores[9];
  // for each possible move, calculate best possible move scores
  for(int i = 0; i < 9; i++) {
    if(board->getPiece(i) == 0) {
      Board* new_board = board->copyBoard();
      new_board->place(piece, i);
      scores[i] = getBestMove(new_board, false);
    } else {
      scores[i] = -15;
    }
  }
  // get first non-empty square index
  int index = 0;
  while(scores[index] < -10) index++;
  if(piece) {
    int max = index++; // make it the starting max
    for(int i = index; i < 9; i++) {
      if(scores[i] >= scores[max]) {
        max = i;
      }
    }
    return max;
  } else {
    int min = index++;
    for(int i = index; i < 9; i++) {
      if(scores[i] > -15 && scores[i] <= scores[min]) {
        min = i;
      }
    }
    return min;
  }
}
