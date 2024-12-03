#include <iostream>
#include <string> 

int getNumber (char number);
int sumEvenDigits (std::string credit_card, int size);
int sumOddDigits (std::string credit_card, int size);

int main () {
  std::cout << "\033[2J\033[1;1H";
  std::cout << "\033[1;37m-------- Credit Card Validator --------\033[0m\n\n";

  std::string credit_card;
  std::cout << "\033[30mType the credit card number: \033[0m";
  std::cin >> credit_card;

  int size = credit_card.length();
  
  int evenSum = sumEvenDigits(credit_card, size);
  int oddSum = sumOddDigits(credit_card, size);

  int result = (evenSum + oddSum) % 10;

  if (result == 0) {
    std::cout << "\033[32mValid credit card number\033[0m" << std::endl;
  } else {
    std::cout << "\033[31mInvalid credit card number\033[0m" << std::endl;
  }

  return 0;
}

int getNumber (char number) {
  return number - '0';
}

int sumEvenDigits (std::string credit_card, int size) {
  int sum = 0;

  for (int index = 0; index < size; index += 2) {
    int number = getNumber(credit_card[index]);
    int double_number = number * 2;

    if (double_number > 9) {
      std::string number_string = std::to_string(double_number);
      sum += getNumber(number_string[0]);
      sum += getNumber(number_string[1]);
      continue;
    }

    sum += double_number;
  }

  return sum;
}

int sumOddDigits (std::string credit_card, int size) {
  int sum = 0;

  for (int index = 1; index < size; index += 2) {
    int number = getNumber(credit_card[index]);
    sum += number;
  }

  return sum;
}