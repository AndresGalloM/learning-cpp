#include <iostream>
#include <cstdlib>
#include <unistd.h> 

void showMenu(int userWins, int computerWins);
int getRandomChoice();
std::string choiceWinner(int userChoice, int computerChoice);

int main () {
  int userChoice;
  int computerChoice;
  int computerWins = 0;
  int userWins = 0;

  while (true) {
    userChoice = 1;
    computerChoice = 1;

    showMenu(userWins, computerWins);

    std::cout << "Enter your choice: ";
    std::cin >> userChoice;

    if (userChoice < 1 || userChoice > 3) {      
      std::cout << "\033[31mInvalid choice. Please enter a number between 1 and 3.\033[0m\n";

      std::cin.clear();
      std::cin.ignore();
      sleep(3);

      continue;
    }

    computerChoice = getRandomChoice();
    std::cout << "Computer choice: " << computerChoice << std::endl << std::endl;

    std::string winner = choiceWinner(userChoice, computerChoice);

    if (winner == "user") userWins++;
    if (winner == "computer") computerWins++;

    sleep(2);
  }

  return 0;
}

void showMenu (int userWins, int computerWins) {
  std::cout << "\033[2J\033[1;1H";

  std::cout << "\033[7m------------ Rock Paper Scissors ------------\033[0m\n";

  std::cout << "\033[31m1. Rock\033[0m  2. Paper  \033[34m3. Scissors\033[0m\n\n";

  std::cout << "\033[32mUser Wins: \033[0m" << userWins << std::endl;
  std::cout << "\033[33mComputer Wins: \033[0m" << computerWins << std::endl << std::endl;
  
  std::cout << "Press `\033[35mcrtl + c\033[0m` to exit" << std::endl << std::endl;
}

int getRandomChoice () {
  srand(time(0));
  int number = rand() % 3 + 1;

  return number;
}

std::string choiceWinner (int userChoice, int computerChoice) {
  if (userChoice == computerChoice) {
    std::cout << "\033[30mIt's a tie!\033[0m" << std::endl;
    return "tie";
  }

  if (
    (userChoice == 1 && computerChoice == 2) ||
    (userChoice == 2 && computerChoice == 3) ||
    (userChoice == 3 && computerChoice == 1)
  ) {
    std::cout << "\033[33mComputer Wins!\033[0m" << std::endl;
    return "computer";
  }

  std::cout << "\033[32mYou Wins!\033[0m" << std::endl;
  return "user";
}