#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

int checkPrecedence(char ch) {
  switch (ch) {
  case '+':
  case '-':
    return 0;
  case '*':
  case '/':
  case '%':
    return 1;
  case '(':
    return -1;
  }
}

char *getPostfixExpr(char *infix) {
  int len = strlen(infix);
  char *postfix = (char *)malloc(sizeof(char) * (len + 1));
  int i = 0, j = 0;
  stack<char> st;

  while (i < len) {
    if (infix[i] == '(') {
      st.push(infix[i]);
    } else if (infix[i] == ')') {
      while (!st.empty() && st.top() != '(') {
        char ch = st.top();
        postfix[j++] = ch;
        st.pop();
      }
      st.pop();
    } else if (isalnum(infix[i])) {
      postfix[j++] = infix[i];
    } else {
      while (!st.empty() &&
             checkPrecedence(infix[i]) <= checkPrecedence(st.top())) {
        char ch = st.top();
        postfix[j++] = ch;
        st.pop();
      }
      st.push(infix[i]);
    }
    i++;
  }

  while (!st.empty()) {
    char ch = st.top();
    postfix[j++] = ch;
    st.pop();
  }

  return postfix;
}

int main() {
  char infix[] = "a*b+c*d/(e+f)-g";
  cout << getPostfixExpr(infix);
  return 0;
}
