#include <iostream>

class QuickSort {
  public:
    void sort(int arr[], int low, int high) {
      if (low >= high) {
        return;
      }

      int pivotIndex = partition(arr, low, high);
      sort(arr, low, pivotIndex - 1);
      sort(arr, pivotIndex + 1, high);
    }

    int partition(int arr[], int low, int high) {      
      int pivot = arr[high];
      int i = 0;
      int j = 0;

      while (i <= high)
      {
        if (arr[i] <= pivot) {
          int temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
          j++;
        }
        i++;
      }

      return j - 1;
    }  
};

int main() {
  QuickSort quickSort;
  int arr[] = {8,-3,5,-2,4,12,-10,-6,1,3};
  int n = sizeof(arr) / sizeof(arr[0]);

  quickSort.sort(arr, 0, n - 1);
  
  for (int num : arr)
  {
    std::cout << num << " ";
  }
  
  return 0;
}