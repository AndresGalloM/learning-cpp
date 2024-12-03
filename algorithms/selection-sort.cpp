#include <iostream>

int main() {
  int numbers[] = {6,1,4,2,7,3,9};
  int length = sizeof(numbers) / sizeof(numbers[0]);

  for (int i = 0; i < length - 1; i++)
  {
    int index_min = -1;
    int min = numbers[i];

    for (int j = i + 1; j < length; j++)
    {
      if (numbers[j] < min)
      {
        min = numbers[j];
        index_min = j;
      }
      
    }

    numbers[index_min] = numbers[i];
    numbers[i] = min;
  }
  
  for (int num : numbers)
  {
    std::cout << num << " ";
  }
  

  return 0;
}