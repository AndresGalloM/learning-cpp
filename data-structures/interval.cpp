#include <iostream>
#include <list>

struct Interval {
  int x;
  int y;

  Interval(int x = 0, int y = 0) : x(x), y(y) {}
};

void merge(Interval arr[], Interval temp[], int left, int mid, int right);
void sortMerge(Interval arr[], Interval temp[], int left, int right);
template <int N>
std::list<Interval> intervalMerge(Interval (&arr)[N]);

int main() {
  Interval interval1(2, 6);
  Interval interval2(7, 8);
  Interval interval3(1, 4);
  Interval interval4(0, 2);
  Interval interval5(5, 6);
  
  Interval arr[] = {interval1, interval2, interval3, interval4, interval5};

  std::cout << "{";
  for (auto interval : intervalMerge(arr)) {
    std::cout << "(" << interval.x << ", " << interval.y << ")" << " ";
  }
  std::cout << "\b}" << std::endl;

  return 0;
}

void merge(Interval arr[], Interval temp[], int left, int mid, int right) {
  int i = left;
  int j = mid + 1;

  for (int k = left; k <= right; k++) {
    temp[k] = arr[k];
  }

  for (int k = left; k <= right; k++) {
    if (i == j) {
      arr[k] = temp[j];
      j++;
      continue;
    }

    if(j > right) {
      arr[k] = temp[i];
      i++;
      continue;
    }
    
    if (temp[i].x < temp[j].x) {
      arr[k] = temp[i];
      i++;
    } else {
      arr[k] = temp[j];
      j++;
    }
  }
}

void sortMerge(Interval arr[], Interval temp[], int left, int right) {
  if (left == right) return;

  int mid = (left + right) / 2;

  sortMerge(arr, temp, left, mid);
  sortMerge(arr, temp, mid + 1, right);
  merge(arr, temp, left, mid, right);
}

template <int N>
std::list<Interval> intervalMerge(Interval (&arr)[N]) {
  Interval temp[N];
  std::list<Interval> result;

  sortMerge(arr, temp, 0, N - 1);
  
  int start = arr[0].x;
  int end = arr[0].y;

  for (int i = 1; i < N; i++) {
    int x = arr[i].x;
    int y = arr[i].y;

    if (x > end) { 
      result.push_back(Interval(start, end));
      start = x;
      end = y;
    } else {
      end = end < y ? y : end;
    }
  }

  result.push_back(Interval(start, end));
  return result;
}