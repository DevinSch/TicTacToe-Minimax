 // Author: Devin Schafthuizen
// Class: CPSC-3750 Artificial Intelligence
// Date: Feb 7th, 2022
// Assignment: 2 - TicTacToe

class Board {

public:
  Board() {
    for (int j = 0; j < 3; j++) {
      for (int i = 0; i < 3; i++) {
        board[i][j] = '-';
      }
    }
  }
  ~Board() {}

  char board[3][3];
  int number_of_moves = 0;

  void draw() {
    std::cout << "|     |     |     |\n|  ";
    if (board[0][0] != '-') {
      std::cout << board[0][0] << "  |  ";
    } else {
      std::cout << '1' << "  |  ";
    }
    if (board[1][0] != '-') {
      std::cout << board[1][0] << "  |  ";
    } else {
      std::cout << '2' << "  |  ";
    }
    if (board[2][0] != '-') {
      std::cout << board[2][0] << "  |\n";
    } else {
      std::cout << '3' << "  |  \n";
    }
    std::cout << "|_____|_____|_____|\n";
    std::cout << "|     |     |     |\n|  ";

    if (board[0][1] != '-') {
      std::cout << board[0][1] << "  |  ";
    } else {
      std::cout << '4' << "  |  ";
    }
    if (board[1][1] != '-') {
      std::cout << board[1][1] << "  |  ";
    } else {
      std::cout << '5' << "  |  ";
    }
    if (board[2][1] != '-') {
      std::cout << board[2][1] << "  |\n";
    } else {
      std::cout << '6' << "  |  \n";
    }
    std::cout << "|_____|_____|_____|\n";
    std::cout << "|     |     |     |\n|  ";

    if (board[0][2] != '-') {
      std::cout << board[0][2] << "  |  ";
    } else {
      std::cout << '7' << "  |  ";
    }
    if (board[1][2] != '-') {
      std::cout << board[1][2] << "  |  ";
    } else {
      std::cout << '8' << "  |  ";
    }
    if (board[2][2] != '-') {
      std::cout << board[2][2] << "  |\n";
    } else {
      std::cout << '9' << "  |\n";
    }
    std::cout << "|_____|_____|_____|\n\n";
  }

  bool drawState() {
    if (number_of_moves == 9) {
      return true;
    }
    return false;
  }

  bool winningState(char player);

  bool updateSquare(int position, char player) {
    char square = '0' + position;

    switch(position) {
      case 1:
        if (board[0][0] == '-') {
          board[0][0] = player;
          number_of_moves += 1;
          return 1;
        }
        break;
      case 2:
        if (board[1][0] == '-') {
          board[1][0] = player;
          number_of_moves += 1;
          return 1;
        }
        break;
      case 3:
        if (board[2][0] == '-') {
          board[2][0] = player;
          number_of_moves += 1;
          return 1;
        }
        break;
      case 4:
        if (board[0][1] == '-') {
          board[0][1] = player;
          number_of_moves += 1;
          return 1;
        }
        break;
      case 5:
        if (board[1][1] == '-') {
          board[1][1] = player;
          number_of_moves += 1;
          return 1;
        }
        break;
      case 6:
        if (board[2][1] == '-') {
          board[2][1] = player;
          number_of_moves += 1;
          return 1;
        }
        break;
        case 7:
          if (board[0][2] == '-') {
            board[0][2] = player;
            number_of_moves += 1;
            return 1;
          }
          break;
        case 8:
          if (board[1][2] == '-') {
            board[1][2] = player;
            number_of_moves += 1;
            return 1;
          }
          break;
        case 9:
          if (board[2][2] == '-') {
            board[2][2] = player;
            number_of_moves += 1;
            return 1;
          }
          break;
      default:
        return 0;
        break;
    }
    return 0;
  }
};

bool Board::winningState(char player) {
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return true;
    }
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return true;
    }
  }
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true;
  }
  return false;
}
