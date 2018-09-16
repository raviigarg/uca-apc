#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

int check_redundancy(char *str) {
  stack<char> st;
  int flag = 0;
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    if (str[i] == '(' || str[i] == '+' || str[i] == '-' || str[i] == '*' ||
        str[i] == '/')
      st.push(str[i]);
    else if (str[i] == ')') {
      while (!st.empty() && st.top() != '(') {
        if (st.top() == '+' || st.top() == '-' || st.top() == '*' ||
            st.top() == '/') {
          flag = 1;
          st.pop();
        }
      }
      if (flag == 1) {
        st.pop();
        flag = 0;
      } else if (!st.empty())
        return 1;
    }
  }

  return 0;
}

int main() {
  char braces_str[] = "((a+b+c))";
  if (check_redundancy(braces_str))
    cout << "Braces are redundant";
  else
    cout << "Braces are not redundant";
  return 0;
}
