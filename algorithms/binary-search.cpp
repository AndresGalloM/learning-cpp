#include <iostream>

int main() {
  int numbers[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49};
  int number = 22;
  
  int start = 0;
  int end = sizeof(numbers) / sizeof(numbers[0]) - 1;

  while (start <= end) {
    std::cout << start << "-" << end << std::endl;
    int middle = (start + end) / 2;

    if (numbers[middle] == number) {
      std::cout << "Number found at index: " << middle << std::endl;
      return 0;
    }

    if (numbers[middle] < number) {
      start = middle + 1;
    } else {
      end = middle - 1;
    }
  }

  std::cout << "Number not found" << std::endl;

  return 0;
}