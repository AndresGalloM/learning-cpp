#include <iostream>

int main() {
  int numbers[] = {5,8,4,2,6,3,1};
  int n = sizeof(numbers) / sizeof(numbers[0]);

  for (int i = 0; i < n; i++) {
    bool isSwapped = false;

    for (int j = 0; j < n - i - 1; j++) {
      if (numbers[j] > numbers[j + 1]) {
        int temp = numbers[j];
        numbers[j] = numbers[j + 1];
        numbers[j + 1] = temp;
        isSwapped = true;
      }
    }
    
    if (!isSwapped) break;
  }
  
  for (int i = 0; i < n; i++)
  {
    std::cout << numbers[i] << " ";
  }

  return 0;
}