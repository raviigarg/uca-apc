#include <iostream>
#include <stack>

using namespace std;

int max_area_histogram(int *hist, int size) {
  int max_area = 0, i = 0;
  int area_with_top = 0;
  stack<int> st;
  for (i = 0; i < size;) {
    if (st.empty() || hist[st.top()] <= hist[i])
      st.push(i++);
    else {
      int top = st.top();
      st.pop();
      area_with_top = hist[top] * (st.empty() ? i : i - st.top() - 1);
      if (max_area < area_with_top)
        max_area = area_with_top;
    }
  }

  while (!st.empty()) {
    int top = st.top();
    st.pop();
    area_with_top = hist[top] * (st.empty() ? i : i - st.top() - 1);
    if (max_area < area_with_top)
      max_area = area_with_top;
  }
  return max_area;
}

int main() {
  int arr[] = {2, 1, 5, 6, 2, 3};
  int size = sizeof(arr) / sizeof(arr[0]);
  cout << max_area_histogram(arr, size);
  return 0;
}
