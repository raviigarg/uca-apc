#include <iostream>
#include <stack>

using namespace std;

void get_nearest_smallest_element(int *arr, int size) {
  stack<int> s;
  int i = 0;
  for (i = 0; i < size; i++) {
    while (!s.empty() && s.top() >= arr[i])
      s.pop();

    if (s.empty())
      cout << -1 << " ";
    else
      cout << s.top() << " ";

    s.push(arr[i]);
  }
}

int main() {
  int arr[] = {4, 5, 2, 10, 8};
  int size = sizeof(arr) / sizeof(arr[0]);

  get_nearest_smallest_element(arr, size);
  return 0;
}
