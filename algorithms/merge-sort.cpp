#include <iostream>

class MergeSort {
  public:
   void megerSort(int arr[], int temp[], int left, int right) {
    if (left < right) {
      int mid = (right + left) / 2;

      megerSort(arr, temp, left, mid);
      megerSort(arr, temp, mid + 1, right);
      merge(arr, temp, left, mid, right);
    }
   }

   void merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    
    for (int i = left; i <= right; i++)
    {
      temp[i] = arr[i];
    }

    for (int s = left; s <= right; s++)
    {
      if (i == mid + 1) {
        arr[s] = temp[j];
        j++;
        continue;
      } else if (j == right + 1) {
        arr[s] = temp[i];
        i++;
        continue;
      }

      if (temp[i] < temp[j]) {
        arr[s] = temp[i];
        i++;
      } else {
        arr[s] = temp[j];
        j++;
      }
    }    
   }
};

int main() {
  MergeSort mergeSort;
  int arr[] = {5,1,4,7,2,9,-1,0};
  int n = sizeof(arr) / sizeof(arr[0]);
  int temp[n];
  mergeSort.megerSort(arr, temp, 0, n - 1);

  for (int num : arr)
  {
    std::cout << num << " ";
  }
   
  
  return 0;
}