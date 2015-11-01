#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
using namespace std;

bool tie = false;

void drawBoard(int tiles[]) {
  stringstream ss;
  system("cls");
  string board[9][3];
  for(int i=0;i<9;i++) {
    if(tiles[i]==1) {
      board[i][0] = "\\ /";
      board[i][1] = " X ";
      board[i][2] = "/ \\";
    } else if(tiles[i]==2) {
      board[i][0] = "/ \\";
      board[i][1] = "| |";
      board[i][2] = "\\ /";
    } else {
      ss.clear();
      ss.str("");
      ss << " " << i+1 << " ";
      board[i][0] = "   ";
      board[i][1] = ss.str();
      board[i][2] = "   ";
    }
  }
  for(int i=0;i<3;i++) {
    for(int j=0;j<4;j++) {
      int mult = 3 * i;
      if(j<3) {
        cout
        << setw(1)
        << " "
        << setw(3)
        << board[mult][j]
        << " | "
        << board[mult+1][j]
        << " | "
        << board[mult+2][j]
        << endl;
      } else if(i<2) {
        cout << setw(17) << "-----------------" << endl;
      }
    }
  }
}

int checkWin(int tiles[]) {
  int count = 0;
  for(int i=0;i<9;i++) {
    if(tiles[i] > 0) {
      count++;
    }
  }
  if(count > 4) {
    for(int i=0;i<9;i++) {
      if(tiles[i] == 1 || tiles[i] == 2) {
        int p = tiles[i];
        if(i == 0) {
          if(tiles[1] == p && tiles[2] == p) {return p;} // 1,2,3
          else if(tiles[3] == p && tiles[6] == p) {return p;} // 1,4,7
          else if(tiles[4] == p && tiles[8] == p) {return p;}} // 1,5,9
        else if(i == 1) {if(tiles[4] == p && tiles[7] == p) {return p;}} // 2,5,8
        else if(i == 2) {if(tiles[4] == p && tiles[6] == p) {return p;} // 3,5,7
          else if(tiles[5] == p && tiles[8] == p) {return p;}} // 3,6,9
        else if(i == 3) {if(tiles[4] == p && tiles[5] == p) {return p;}} // 4,5,6
        else if(i == 6) {if(tiles[7] == p && tiles[8] == p) {return p;}} // 7,8,9
        else if(count > 8) {return 3;} // All tiles, no win
      }
    }
  }
  return 0;
}

int main() {
  int tiles[9] = {};
  string raw;
  int tileChoice;
  string turn = "X";
  int winner;
  drawBoard(tiles);
  cout << "Welcome to tic tac toe. ";
  while(true) {
    cout << "Player " << turn << ", please pick a tile: ";
    getline(cin, raw);
    stringstream(raw) >> tileChoice;
    if(tileChoice > 0 && tileChoice < 10 && tiles[(tileChoice-1)] == 0) {
      if(turn == "X") {
        tiles[(tileChoice-1)] = 1;
        turn = "O";
      } else {
        tiles[(tileChoice-1)] = 2;
        turn = "X";
      }
    } else {
      continue;
    }
    drawBoard(tiles);
    winner = checkWin(tiles);
    if(winner > 0) {
      if(winner == 1) {
        cout << "Player X wins!";
      } else if(winner == 2) {
        cout << "Player O wins!";
      } else {
        cout << "It's a tie!";
      }
      break;
    }
  }
  return 0;
}
