#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

string simple_path(string str) {
  string res_str;
  res_str.append("/");

  stack<string> st;
  string dir_name;
  int len = str.length();

  for (int i = 0; i < len; i++) {
    dir_name.clear();

    while (str[i] == '/')
      i++;

    while (i < len && str[i] != '/') {
      dir_name.push_back(str[i++]);
    }

    if (dir_name.compare("..") == 0) {
      if (!st.empty())
        st.pop();
    }

    else if (dir_name.compare(".") == 0) {
      continue;
    }

    else if (dir_name.length() != 0)
      st.push(dir_name);
  }

  stack<string> st1;
  while (!st.empty()) {
    st1.push(st.top());
    st.pop();
  }

  while (!st1.empty()) {
    string temp = st1.top();

    if (st1.size() != 1)
      res_str.append(temp + "/");
    else
      res_str.append(temp);
    st1.pop();
  }

  return res_str;
}

int main() {
  string path("/../../../../a/b/../c/./d///./e/../");
  cout << simple_path(path);
  return 0;
}
