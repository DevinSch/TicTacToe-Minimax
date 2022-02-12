// Author: Devin Schafthuizen
// Class: CPSC-3750 Artificial Intelligence
// Date: Feb 7th, 2022
// Assignment: 2 - TicTacToe
#include <iostream>
#include "./Game.h"

void testing(Board test);
void getPlayerInput(GameState& play_space); // player input
void minimax(bool max, int alpha, int beta); // Ai input
void gameLoop(GameState current);

int main() {
  Board test;

  GameState newWorld(test);

  gameLoop(newWorld);
  //testing(test);
  std::cout << "\n\nTest Complete\n";
}

void testing(Board test) {
  test.updatePos(5,'X');
  test.drawTable();
  test.updatePos(5,'O');
  test.drawTable();

  GameState start(test);
}

void getPlayerInput(GameState& play_space) {
  int input;

  std::cout << "Please pick a square :";
  std::cin >> input;

  // Check for vaild inputs ***** Maybe

  play_space.table.updatePos(input,'X');
}

void minimax(bool max, int alpha, int beta) {

  // is max player
      // check for winning state
      // check for tie state
      // call minimax for min player

  // is min player
      // check for winning state
      // check for tie state
      // call minimax for max player
}

void gameLoop(GameState current) {
  bool play_on = 1;

  while(play_on == true) {
    // print the Board
    current.draw();

    // Get player input
    getPlayerInput(current);

    // check for win
    if (current.winningState() != 'C') {
      std::cout << "Game over, player " << current.winningState() << " won the game!\n";
      break;
    }

    // check for draw
    if (current.drawState() == true) {
      std::cout << "Scratch game, no winner\n";
      break;
    }

    // ai / minimax

    // check for win

    // check for draw

  }
  current.draw();
}
