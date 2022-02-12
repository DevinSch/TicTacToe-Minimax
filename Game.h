// Author: Devin Schafthuizen
// Class: CPSC-3750 Artificial Intelligence
// Date: Feb 7th, 2022
// Assignment: 2 - TicTacToe

class Board {
public:
  Board() {}
  ~Board() {}

  Board & operator = (Board copy) {
    for (int i = 0; i < 10; i++) {
      this->pos[i] = copy.pos[i];
    }
    this->number_moves = copy.number_moves;
    return *this;
  }

  void drawTable() {
    std::cout << "|     |     |     |\n";
    std::cout << "|  " << pos[1] << "  |  " << pos[2] << "  |  " << pos[3] << "  |\n";
    std::cout << "|_____|_____|_____|\n";
    std::cout << "|     |     |     |\n";
    std::cout << "|  " << pos[4] << "  |  " << pos[5] << "  |  " << pos[6] << "  |\n";
    std::cout << "|_____|_____|_____|\n";
    std::cout << "|     |     |     |\n";
    std::cout << "|  " << pos[7] << "  |  " << pos[8] << "  |  " << pos[9] << "  |\n";
    std::cout << "|_____|_____|_____|\n\n";
  }

  bool updatePos(int position, char player) {
    char square = '0' + position;
    if (pos[position] != square) {
      std::cout << "Location taken! " << square << " " << player << "\n";
      return 0; // Already taken!
    } else if (pos[position] == square) {
      std::cout << "Square " << square << " to player " << player << "\n";
      pos[position] = player; // Update whos in the square
      number_moves++;
      return 1;
    }
    return 0;
  }

  int getMoves() {return number_moves;}

  char pos[10] = {'0','1','2','3','4','5','6','7','8','9'};
  int number_moves = 0;
};

class GameState {
public:
  GameState(Board input) {table = input;}
  ~GameState() {}

  void draw() {table.drawTable();}

  char winningState();

  bool drawState() {
    if (table.getMoves() > 8) {
      return true;
    } else {
      return false;
    }
  }

//private:
  Board table;
private:
};

char GameState::winningState() {
  if (table.pos[1] == table.pos[2] && table.pos[2] == table.pos[3]) {
    return table.pos[1];
  } else if (table.pos[4] == table.pos[5] && table.pos[5] == table.pos[6]) {
    return table.pos[4];
  } else if (table.pos[7] == table.pos[8] && table.pos[8] == table.pos[9]) {
    return table.pos[7];
  } else if (table.pos[1] == table.pos[4] && table.pos[4] == table.pos[7]) {
    return table.pos[1];
  } else if (table.pos[2] == table.pos[5] && table.pos[5] == table.pos[8]) {
    return table.pos[2];
  } else if (table.pos[3] == table.pos[6] && table.pos[6] == table.pos[9]) {
    return table.pos[3];
  } else if (table.pos[1] == table.pos[5] && table.pos[5] == table.pos[9]) {
    return table.pos[1];
  } else if (table.pos[3] == table.pos[5] && table.pos[5] == table.pos[7]) {
    return table.pos[3];
  } else {
    return 'C';
  }
}
