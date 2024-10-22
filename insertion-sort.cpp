#include <iostream>

int main() {
  int numbers[] = {5,2,6,3,7,1,5};
  int lenght = sizeof(numbers) / sizeof(numbers[0]);

  for (int i = 1; i < lenght; i++)
  {
    int num = numbers[i];

    for (int j = i-1; j >= 0; j--)
    {
      if (numbers[j] > num) {
        numbers[j+1] = numbers[j];
        numbers[j] = num;
      } else {
        break;
      }
    }
  }

  for (int num : numbers)
  {
    std::cout << num << " ";
  }
  
  return 0;
}