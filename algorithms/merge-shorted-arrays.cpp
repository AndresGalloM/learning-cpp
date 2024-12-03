#include <iostream>

int main() {
  int array1[] = {2,4,6,8,10,12};
  int array1_size = sizeof(array1) / sizeof(array1[0]);
  
  int array2[] = {1,3,5,7,9,11};
  int array2_size = sizeof(array2) / sizeof(array2[0]);

  int size_merged_array = array1_size + array2_size;
  int merged_arrray[size_merged_array];

  int i = 0;
  int j = 0;

  for (int k = 0; k < size_merged_array; k++)
  {
    if (i == array1_size) {
      merged_arrray[k] = array2[j];
      j++;
      continue;
    } else if (j == array2_size) {
      merged_arrray[k] = array1[i];
      i++;
      continue;
    }

    if (array1[i] < array2[j]) {
      merged_arrray[k] = array1[i];
      i++;
    } else {
      merged_arrray[k] = array2[j];
      j++;
    }
  }
  
  for (int num : merged_arrray)
  {
    std::cout << num << " ";
  }
  
  return 0;
}