#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

int is_balanced(char *s, int size) {
  stack<char> st;
  if (size % 2 != 0)
    return 0;
  else {
    for (int i = 0; i < size; i++) {
      if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
        st.push(s[i]);
      } else if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
        if (!((s[i] == '}' && st.top() == '{') ||
              (s[i] == ']' && st.top() == '[') ||
              (s[i] == ')' && st.top() == '(')))
          return 0;
        else
          st.pop();
      } else {
        return 0;
      }
    }
  }
  return st.empty();
}

int main() {
  char s[] = "{()[()]}{}([]){}";
  int size = sizeof(s) / sizeof(s[0]) - 1;
  if (is_balanced(s, size)) {
    printf("Paranthesis are balanced");
  } else {
    printf("Paranthesis are not balanced");
  }
}
