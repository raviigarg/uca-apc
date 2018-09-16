#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int evaluate_expression(vector<string> &exp) {
  stack<int> st;

  for (unsigned int i = 0; i < exp.size(); i++) {
    if (exp[i] == "+" || exp[i] == "-" || exp[i] == "*" || exp[i] == "/") {
      int first = st.top();
      st.pop();
      int second = st.top();
      st.pop();

      if (exp[i] == "+")
        st.push(second + first);
      else if (exp[i] == "-")
        st.push(second - first);
      else if (exp[i] == "*")
        st.push(second * first);
      else if (exp[i] == "/")
        st.push(second / first);
    } else
      st.push(atoi(exp[i].c_str()));
  }

  return st.top();
}

int main() {

  vector<string> exp = {"4", "13", "5", "/", "+"};

  cout << evaluate_expression(exp);

  return 0;
}
