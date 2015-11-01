#include <iostream>
#include <sstream>
#include <stdlib.h>
using namespace std;

// This holds the important stuff, what squares are x, what squares are o, and
// what squares are empty, and if a tile is won, the squares will be updated to
// the corresponding picture
string tileData[9][9];
// This keeps track of what tiles have been won
int tileWins[9] = {};

// This draws the board
void drawBoard() {
  system("cls"); // Clear screen
  for(int i=1;i<18;i++) {
    if(i % 2 == 0) {
      if(i % 6 == 0) {
        cout << "-----------|-----------|-----------"; // This is run twice
      } else {
        cout << "---|---|---|---|---|---|---|---|---"; // This is run every other loop
      }
    } else {
      for(int j=1;j<36;j++) {
        if(j % 2 == 1) {
          cout << " "; // Separating space
        } else {
          if(j % 4 == 0) {
            cout << "|"; // Vertical separators
          } else {
            // Print the data from tileData based on i and j
            cout << tileData[((((j-2)/4)/3)+((i/6)*3))][((((j-2)/4)%3)+(((i%6)/2)*3))]; // You don't need to know how this works, it just does
          }
        }
      }
    }
    cout << endl;
  }
}

// This sets the values in tileData for a specific tile to the corresponding picture
void tileWin(int tile, string player) {
  if(player == "X") {
    tileData[tile][0] = "\\";
    tileData[tile][1] = " ";
    tileData[tile][2] = "/";
    tileData[tile][3] = " ";
    tileData[tile][4] = "X";
    tileData[tile][5] = " ";
    tileData[tile][6] = "/";
    tileData[tile][7] = " ";
    tileData[tile][8] = "\\";
    tileWins[tile] = 1;
  } else if(player == "O") {
    tileData[tile][0] = "/";
    tileData[tile][1] = " ";
    tileData[tile][2] = "\\";
    tileData[tile][3] = "|";
    tileData[tile][4] = "O";
    tileData[tile][5] = "|";
    tileData[tile][6] = "\\";
    tileData[tile][7] = " ";
    tileData[tile][8] = "/";
    tileWins[tile] = 2;
  } else {
    tileData[tile][0] = "*";
    tileData[tile][1] = "*";
    tileData[tile][2] = "*";
    tileData[tile][3] = "*";
    tileData[tile][4] = "*";
    tileData[tile][5] = "*";
    tileData[tile][6] = "*";
    tileData[tile][7] = "*";
    tileData[tile][8] = "*";
    tileWins[tile] = 3;
  }
}

// This checks all the win states for a small board
int checkWinTile(int tile) {
  int count = 0;
  for(int i=0;i<9;i++) {
    if(tileData[tile][i] == "X" || tileData[tile][i] == "O") {
      count++;
    }
  }
  if(count > 2) {
    for(int i=0;i<9;i++) {
      if(tileData[tile][i] == "X" || tileData[tile][i] == "O") {
        string p = tileData[tile][i];
        if(i == 0) {
          if(tileData[tile][1] == p && tileData[tile][2] == p) {return 1;} // 1,2,3
          else if(tileData[tile][3] == p && tileData[tile][6] == p) {return 1;} // 1,4,7
          else if(tileData[tile][4] == p && tileData[tile][8] == p) {return 1;}} // 1,5,9
        else if(i == 1) {if(tileData[tile][4] == p && tileData[tile][7] == p) {return 1;}} // 2,5,8
        else if(i == 2) {if(tileData[tile][4] == p && tileData[tile][6] == p) {return 1;} // 3,5,7
          else if(tileData[tile][5] == p && tileData[tile][8] == p) {return 1;}} // 3,6,9
        else if(i == 3) {if(tileData[tile][4] == p && tileData[tile][5] == p) {return 1;}} // 4,5,6
        else if(i == 6) {if(tileData[tile][7] == p && tileData[tile][8] == p) {return 1;}} // 7,8,9
        else if(count > 8) {return 2;} // All tiles, no win
      }
    }
  }
  return 0;
}

// This checks the win states for the big grid
int checkWinGame() {
  int count = 0;
  for(int i=0;i<9;i++) {
    if(tileWins[i] > 0) {
      count++;
    }
  }
  if(count > 2) {
    for(int i=0;i<9;i++) {
      if(tileWins[i] == 1 || tileWins[i] == 2) {
        int p = tileWins[i];
        if(i == 0) {
          if(tileWins[1] == p && tileWins[2] == p) {return p;} // 1,2,3
          else if(tileWins[3] == p && tileWins[6] == p) {return p;} // 1,4,7
          else if(tileWins[4] == p && tileWins[8] == p) {return p;}} // 1,5,9
        else if(i == 1) {if(tileWins[4] == p && tileWins[7] == p) {return p;}} // 2,5,8
        else if(i == 2) {if(tileWins[4] == p && tileWins[6] == p) {return p;} // 3,5,7
          else if(tileWins[5] == p && tileWins[8] == p) {return p;}} // 3,6,9
        else if(i == 3) {if(tileWins[4] == p && tileWins[5] == p) {return p;}} // 4,5,6
        else if(i == 6) {if(tileWins[7] == p && tileWins[8] == p) {return p;}} // 7,8,9
        else if(count > 8) {return 3;} // All tiles, no win
      }
    }
  }
  return 0;
}

// This runs through the steps to update a tile, including updating
// tileData and then checking for a win. Finally, it redraws the board
// after everything is updated
bool updateTile(int tile, int square, string player) {
  tile--;
  square--;
  if(player == "X") {
    tileData[tile][square] = "X";
  } else {
    tileData[tile][square] = "O";
  }
  drawBoard();
  int tileWinState = checkWinTile(tile);
  if(tileWinState > 1) {
    tileWin(tile, "tie");
    drawBoard();
  } else if(tileWinState > 0) {
    tileWin(tile, player);
    drawBoard();
  }
  int gameWinState = checkWinGame();
  if(gameWinState == 1) {
    cout << "X has won!" << endl;
    return true;
  } else if(gameWinState == 2) {
    cout << "O has won!" << endl;
    return true;
  } else if(gameWinState == 3) {
    cout << "It's a tie!" << endl;
    return true;
  }
  return false;
}

// Checks if an integer is a valid tile number 1 - 9
bool isTile(int tile) {
  if(tile > 0 && tile < 10)
    return true;
  return false;
}

// Checks to see if a tile has already been won
bool isTileWon(int tile) {
  if(tileWins[tile-1] > 0)
    return true;
  return false;
}

// Makes sure user picks a valid tile before attempting to play. Also handles
// the case of a picked tile being won already
int pickTile(int tileChoice, string player) {
  string raw;
  bool valid = false;
  if(isTile(tileChoice) && !isTileWon(tileChoice)) {
    valid = true;
  }
  while(!valid) {
    drawBoard();
    if(isTile(tileChoice)) {
      cout << "Tile " << tileChoice << " has already been finished." << endl;
    }
    cout << "Player " << player << " please pick a tile: ";
    getline(cin, raw);
    stringstream(raw) >> tileChoice;
    if(isTile(tileChoice) && !isTileWon(tileChoice))
      valid = true;
  }
  return tileChoice;
}

// Main game logic
int main() {
  stringstream con;
  for(int i=0;i<9;i++) {
    for(int j=0;j<9;j++) {
      con.clear();
      con.str("");
      con << j + 1;
      tileData[i][j] = con.str();
    }
  }
  drawBoard();
  string player = "X";
  string raw = "";
  stringstream prevPlay;
  prevPlay.str("");
  int tileChoice = 0;
  int squareChoice;
  bool gameOver = false;
  cout << "Welcome to Tic Tac Toe Plus! ";
  do {
    tileChoice = pickTile(tileChoice, player); // Validate tile choice
    cout << prevPlay.str(); // Just a helpful line that outputs the last move played
    cout << "Player " << player << " please pick a square in tile " << tileChoice << ": "; // Pick a square
    getline(cin, raw);
    stringstream(raw) >> squareChoice; // Convert to integer
    if(squareChoice > 0 && squareChoice < 10) { // Make sure it's a valid square choice
      string data = tileData[tileChoice-1][squareChoice-1]; // Extra variable to shorten the next line
      if(data != "X" && data != "O") { // Check to make sure tileData is not already filled with x or o
        prevPlay.clear();
        prevPlay.str("");
        prevPlay << "Player " << player << " picked square " << squareChoice << " in tile " << tileChoice << "." << endl; // Set previous play made
        gameOver = updateTile(tileChoice, squareChoice, player); // Update tile, this does everything include checking for any wins, gameOver is set to true when a player wins
        if(player == "X") {player = "O";} else {player = "X";} // Set next player's turn
        tileChoice = squareChoice; // tileChoice is now equal to squareChoice, will be validated in next loop iteration
      }
    }
  } while(!gameOver);
  return 0;
}
