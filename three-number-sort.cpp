#include <iostream>

enum AllowNumbers {
  ZERO,
  ONE,
  TWO
};

class ThreeNumberSort {
  public:
    void sort(AllowNumbers arr[], int size) {      
      int i = 0;
      int j = 0;
      int k = size - 1;

      while (i <= k)
      {
        if (arr[i] == 0) {
          swap(arr, i, j);
          i++;
          j++;
        } else if (arr[i] == 1) {
          i++;
        } else if (arr[i] == 2) {
          swap(arr, i, k);
          k--;
        }
      }
    }

    void swap(AllowNumbers arr[], int a, int b) {
      AllowNumbers temp = arr[a];
      arr[a] = arr[b];
      arr[b] = temp;
    } 
};

int main() {
  AllowNumbers arr[] = {TWO, ZERO, ONE, TWO, ZERO, ONE};
  int size = sizeof(arr) / sizeof(arr[0]);
  ThreeNumberSort ThreeNumberSort;

  ThreeNumberSort.sort(arr, size);

  for (int num : arr)
  {
    std::cout << num << " ";
  }
  
  return 0;
}