#include <deque>
#include <iostream>

using namespace std;

void get_sliding_window_maximum(int *arr, int size, int k) {
  deque<int> q(k);

  int i;
  for (i = 0; i < k; i++) {
    while (!q.empty() && arr[i] >= arr[q.back()])
      q.pop_back();
    q.push_back(i);
  }

  for (; i < size; i++) {
    cout << arr[q.front()] << " ";

    while (!q.empty() && q.front() <= i - k)
      q.pop_front();

    while (!q.empty() && arr[i] >= arr[q.back()])
      q.pop_back();

    q.push_back(i);
  }

  cout << arr[q.front()];
}

int main() {
  int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
  int size = sizeof(arr) / sizeof(arr[0]);
  get_sliding_window_maximum(arr, size, 3);
  return 0;
}
