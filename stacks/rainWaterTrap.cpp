#include <iostream>
#include <stack>

using namespace std;

int maxWater(int *heights, int size) {
  stack<int> st;
  int i = 0;
  int ans = 0;
  while (i < size) {
    while (!st.empty() && heights[i] > heights[st.top()]) {
      int top = st.top();
      st.pop();
      if (st.empty())
        break;
      int dis = i - st.top() - 1;
      // printf("%d\t", dis);

      int bounded_h = min(heights[i], heights[st.top()]) - heights[top];
      // printf("%d\t", bounded_h);

      ans += dis * bounded_h;
    }

    st.push(i++);
  }
  // printf("\n");
  return ans;
}

int main() {
  int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 1, 2, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  cout << maxWater(arr, size);
  return 0;
}
