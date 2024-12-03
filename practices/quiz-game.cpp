#include <iostream>
#include <cctype>
#include <unistd.h>

int main () {
  std::string questions[] = {
    "1. What year was C++ created?",
    "2. Who invented C++?",
    "3. What is the predecessor of C++?"
  };

  std::string options[][4] = {
    {"A. 1979", "B. 1985", "C. 1982", "D. 1894"},
    {"A. Guido van Rossum", "B. Dennis Ritchie", "C. Bjarne Stroustrup", "D. Graydon Hoare"},
    {"A. C", "B. C#", "C. C+", "D. C-"}
  };

  char answers[] = {'B', 'C', 'A'};
  int goodResponses = 0;
  int questions_size = sizeof(questions) / sizeof(std::string);

  for (int qst_index = 0; qst_index < questions_size; qst_index++) {
    std::cout << "\033[2J\033[1;1H";
    std::cout << "\033[1;37m-------- Welcome to the C++ Quiz! --------\033[0m\n\n";

    std::cout << "\033[33mCurrent Score: " << goodResponses << "/3\033[0m\n\n";

    std::cout << "\033[30m" << questions[qst_index] << "\033[0m\n\n";

    for (std::string option : options[qst_index]) {
      std::cout << "    " << option << '\n';
    }
    
    char user_answer;
    std::cout << "\n\033[36mEnter your answer: \033[0m";
    std::cin >> user_answer;

    if (std::toupper(user_answer) == answers[qst_index]) {
      goodResponses++;
      std::cout << "\033[32mCorrect!"<< "\033[0m\n\n";
    } else {
      std::cout << "\033[31mIncorrect!\033[0m The correct answer is \033[30m`" << options[qst_index][answers[qst_index] - 65] << "`\033[0m\n\n";
    }

    sleep(2);
  }

  return 0;
}