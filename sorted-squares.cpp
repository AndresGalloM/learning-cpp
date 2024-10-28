#include <iostream>
#include <cmath>

class SortedSquared {
  public:
    int* sortSquares(int arr[], int n) {
      int* result = new int[n];
      int i = 0;
      int j = n - 1;

      for (int k = n - 1; k >= 0; k--)
      {
        int pow_i = std::pow(arr[i], 2);
        int pow_j = std::pow(arr[j], 2);

        if (pow_i < pow_j) {
          result[k] = pow_j;
          j--;
        } else {
          result[k] = pow_i;
          i++;
        }
      }
      
      return result;
    }
};

int main() {
  int arr[] = {-4, -1, 0, 1, 3, 6, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  
  SortedSquared sortedSquared;
  int* result = sortedSquared.sortSquares(arr, n);

  for (int i = 0; i < n; i++)
  {
    std::cout << result[i] << " ";
  }
  
  
  return 0;
}