// Guessing game
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void admin(int ans) {
  cout << "--BEGIN--" << endl;
  string astr;
  cout << "Welcome admin. What would you like to do? ";
  getline(cin, astr);
  if(astr == "win") {
    cout << "The answer to the game is " << ans << ". ";
  }
  getline(cin, astr);
  cout << endl << "--END--" << endl;
  system("cls");
}

int main() {
  srand(time(NULL));
  // Number to be guessed
  const int rnum = rand() % 100 + 1;
  // Number of guesses
  const int gnum = 7;
  // Current number of guesses taken
  int guesstotal = 0;
  // Guess taken from cin
  string raw;
  // Converted guess
  int guess;
  // List of numbers guessed
  stringstream glist;

  system("cls");
  cout << "Welcome to the guessing game." << endl;

  while(guesstotal < gnum) {
    if(glist.str().length()>0) {
      cout << "Guesses taken: " << glist.str() << endl;
    }
    cout << "Guesses remaining: " << (gnum - guesstotal) << endl;
    cout << "Please take a guess: ";
    getline(cin, raw);
    stringstream(raw) >> guess;
    if(guess == 150024) {
      admin(rnum);
    }
    else if(guess == rnum) {
      system("cls");
      cout << guess << " is the correct number. You win!";
      break;
    }
    else if(guess < 1 || guess > 100) {
      system("cls");
      cout << guess << " is out of bounds." << endl;
    }
    else if(guess < rnum) {
      system("cls");
      ++guesstotal;
      glist << guess << "- ";
      cout << guess << " is too low." << endl;
    }
    else if(guess > rnum) {
      system("cls");
      ++guesstotal;
      glist << guess << "+ ";
      cout << guess << " is too high." << endl;
    }
  }

  if(guesstotal >= gnum) {
    system("cls");
    cout << "You have run out of guesses. The number was " << rnum << ". Game over.";
  }

  return 0;
}
