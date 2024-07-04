#include <iostream>
#include <ctime>
#include <unistd.h>
#include <cctype>

const int SIZE_MOVES = 9; 
const std::string MOVES[] = {
  "tl", "tc", "tr",
  "cl", "cc", "cr",
  "bl", "bc", "br"
};

const int INDEXS_MOVE[][2] = {
  {0, 0}, {0, 1}, {0, 2},
  {1, 0}, {1, 1}, {1, 2},
  {2, 0}, {2, 1}, {2, 2}
};

void showMenu ();
void drawBoard (char board[][3]);
void playerMove (char board[][3], char turn);
char checkWinner (char board[][3]);
void errorMessage (std::string msg);

int main () {
  char winner = ' ';
  char turn = 'x';

  char board[][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
  };

  while (true) {
    std::cout << "\033[2J\033[1;1H";
    showMenu();

    winner = checkWinner(board);
    drawBoard(board);

    if (winner == '-') {
      std::cout << "\033[35mIt is a tie\033[0m\n";
      break;
    }

    if (winner != ' ') {
      std::string color = winner == 'x' ? "\033[1;31m" : "\033[1;34m";
      std::cout << "Player " << color << (char)std::toupper(winner) << "\033[0m wins!\n";
      break;
    }

    playerMove(board, turn);

    turn = turn == 'x' ? 'o' : 'x';
  }

  return 0;
}

void showMenu () {
  std::cout << "\033[1;37m------------ Tic Tac Toe! ------------\033[0m\n\n";

  std::cout << "\033[3;30mUse t(top) c(center) b(bottom) to rows\n";
  std::cout << "Use l(left) c(center) r(right) to columns\033[0m\n";
  std::cout << "\033[36mExample:\033[0m \033[30mtr (row-column)\033[0m\n\n";
}

void drawBoard (char board[][3]) {  
  for (int row = 0; row < 3; row++) {
    for ( int column = 0; column < 3; column++) {
      char sig = board[row][column];
      std::string color = sig == 'x' ? "\033[1;31m" : "\033[1;34m";

      std::cout << color << " " << sig << "\033[0m";

      if (column != 2) std::cout << "\033[30m |\033[0m";
    }

    if (row == 2) break;
    std::cout << "\n\033[30m---+---+---\033[0m\n";
  }

  std::cout << "\n\n";
}

void playerMove (char board[][3], char turn) {
  std::string player_move;
  int row, column;
  bool valid_move = false;
  bool is_full = false;

  while (!valid_move || is_full) {
    valid_move = false;
    is_full = false;

    std::cout << (turn == 'x' ? "\033[31m[Player 1](X)\033[0m" : "\033[34m[Player 2](O)\033[0m");
    std::cout << "\033[30m enter your move: \033[0m";

    std::cin >> player_move;

    for (int i = 0; i < SIZE_MOVES; i++) {
      if (MOVES[i] == player_move) {
        row = INDEXS_MOVE[i][0];
        column = INDEXS_MOVE[i][1];

        valid_move = true;
        is_full = board[row][column] != ' ';
        break;
      }
    }
    
    if (!valid_move) errorMessage("It is not a valid move");
    if (is_full) errorMessage("The field is full, change your option");
  }

  board[row][column] = turn;
}

char checkWinner (char board[][3]) { 
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return board[i][0];
    }
  }

  for (int i = 0; i < 3; i++) {
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
      return board[0][i];
    }
  }

  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return board[0][0];
  }

  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    return board[0][2];
  }

  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      if (board[row][column] == ' ') {
        return ' ';
      }
    }
  }

  return '-';
}

void errorMessage (std::string msg) {
  std::cout << "\033[33m" << msg << "\033[0m\n";
  std::cout << "\033[A\033[2K\033[A\033[2K";
  sleep(2);
}