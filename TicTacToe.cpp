// Author: Devin Schafthuizen
// Class: CPSC-3750 Artificial Intelligence
// Date: Feb 7th, 2022
// Assignment: 2 - TicTacToe
#include <iostream>
#include <limits>
#include "./Game.h"

void getPlayerInput(Board& play_space); // player input
int minimax(Board& current, int alpha, int beta); // Ai input
int my_min(Board& current, int alpha, int beta);
int my_max(Board& current, int alpha, int beta);
void gameLoop(Board current); // Loops through inputs until game is over

int main() {
  Board TicTacToe;
  gameLoop(TicTacToe);
}

void getPlayerInput(Board& current) {
  int input;
  while (true){
    std::cout << "Please pick a square :";
    if (std::cin >> input) { // checks if input is an int
      if(input < 0 || input > 9) {
        continue;
      } else if (current.updateSquare(input, 'X') == 1) {
        break;
      } else {
        std::cin.clear(); // clears if input is not a number
        std::cin.ignore();
      }
    }
  }
}

int minimax(Board& current, int alpha, int beta) {
  int bestMove = std::numeric_limits<int>::max();
  int position = 1;
  int action = 0;

  for (unsigned int i = 0; i < 3; i++) {
    for (unsigned int j = 0; j < 3; j++) {
        if (current.board[j][i] == '-') {
            current.board[j][i] = 'O';
            int temp = my_max(current, alpha, beta);
            if (temp < bestMove) {
                bestMove = temp;
                action = position;
            }
            current.board[j][i] = '-';
          }
        position += 1;
      }
    }
    std::cout << "Computer plays to position " << action << "\n";
  return action;
}

int my_min(Board& current, int alpha, int beta) {
  if(current.winningState('X') == true) { return 10; }
  else if (current.winningState('O') == true) { return -10; }
  else if (current.drawState()) { return 0; }

  int bestMove = std::numeric_limits<int>::max();
  for (unsigned int i = 0; i < 3; i++) {
      for (unsigned int j = 0; j < 3; j++) {
          if (current.board[j][i] == '-') {
              current.board[j][i] = 'O';
              bestMove = std::min(bestMove, my_max(current, alpha, beta));
              current.board[j][i] = '-';
          }
      }
  }
  return bestMove;
}

int my_max(Board& current, int alpha, int beta) {
  if(current.winningState('X') == true) { return 10; }
  else if (current.winningState('O') == true) { return -10; }
  else if (current.drawState()) { return 0; }

  int bestMove = std::numeric_limits<int>::min();
  for (unsigned int i = 0; i < 3; i++) {
      for (unsigned int j = 0; j < 3; j++) {
          if (current.board[j][i] == '-') {
              current.board[j][i] = 'X';
              bestMove = std::max(bestMove, my_min(current, alpha, beta));
              current.board[j][i] = '-';
          }
      }
  }
  return bestMove;
}

void gameLoop(Board current) {
  bool play_on = 1;
  int ai_input;

  while(play_on == true) {

    // ai input through minimax
    ai_input = minimax(current, 0, 0);
    current.updateSquare(ai_input, 'O');

    // check for win
    if (current.winningState('O') == true) {
      std::cout << "Game over, player O won the game!\n";
      break;
    }

    // check for draw
    if (current.drawState() == true) {
      std::cout << "Scratch game, no winner\n";
      break;
    }

    // print the Board
    current.draw();

    // Get player input
    getPlayerInput(current);

    // check for win
    if (current.winningState('X') == true) {
      std::cout << "Game over, player X won the game!\n";
      break;
    }

    // check for draw
    if (current.drawState() == true) {
      std::cout << "Scratch game, no winner\n";
      break;
    }
  }
  current.draw();
}
