#include <iostream>
#include <queue>
#include <stack>
#include <stdlib.h>

using namespace std;

typedef struct BTree {
  int data;
  struct BTree *left;
  struct BTree *right;
} BTree;

BTree *make_binary_tree(BTree *root, int d) {
  BTree *nn = new BTree();
  nn->data = d;
  nn->left = NULL;
  nn->right = NULL;

  if (root == NULL) {
    return nn;
  } else {
    queue<BTree *> q;
    q.push(root);
    while (!q.empty()) {
      BTree *node = q.front();
      q.pop();
      if (node->left) {
        q.push(node->left);
      } else {
        node->left = nn;
        return root;
      }

      if (node->right) {
        q.push(node->right);
      } else {
        node->right = nn;
        return root;
      }
    }
  }
}

void inorder_traversal(BTree *root) {
  stack<BTree *> st;
  while (1) {
    while (root) {
      st.push(root);
      root = root->left;
    }

    if (st.empty())
      return;

    BTree *node = st.top();
    st.pop();

    cout << node->data << " ";
    root = node->right;
  }
}

void preorder_traversal(BTree *root) {
  stack<BTree *> st;
  while (1) {
    while (root) {
      st.push(root);
      cout << root->data << " ";
      root = root->left;
    }

    if (st.empty())
      return;

    BTree *node = st.top();
    st.pop();
    root = node->right;
  }
}

void post_order_traversal(BTree *root) {
  stack<BTree *> st;

  if (root == NULL)
    return;

  // using one stack

  do {
    while (root != NULL) {
      if (root->right)
        st.push(root->right);
      st.push(root);
      root = root->left;
    }

    root = st.top();
    st.pop();
    if (st.empty())
      break;
    if (root->right != NULL && st.top() == root->right) {
      st.pop();
      st.push(root);
      root = root->right;
    } else {
      cout << root->data << " ";
      root = NULL;
    }
  } while (!st.empty());

  cout << root->data;

  // using two stacks

  /*
    st.push(root);

    stack<int> out;

    while (!st.empty()) {
      BTree *curr = st.top();
      st.pop();
      out.push(curr->data);

      if (curr->left)
        st.push(curr->left);

      if (curr->right)
        st.push(curr->right);
    }

    while (!out.empty()) {
      cout << out.top() << " ";
      out.pop();
    } */
}

int main() {
  BTree *root = NULL;
  int n;
  printf("Enter no of nodes: ");
  scanf("%d", &n);
  printf("Enter data:\n");
  for (int i = 0; i < n; i++) {
    int d;
    scanf("%d", &d);
    root = make_binary_tree(root, d);
  }

  cout << "Inorder Traversal:" << endl;
  inorder_traversal(root);
  cout << endl << "Preorder Traversal:" << endl;
  preorder_traversal(root);
  cout << endl << "Post order traversal:" << endl;
  post_order_traversal(root);
  cout << endl;
  return 0;
}
