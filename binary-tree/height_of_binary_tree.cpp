#include <iostream>
#include <queue>
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

int height_of_tree(BTree *root) {
  if (root == NULL) {
    return 0;
  } else
    return 1 + max(height_of_tree(root->left), height_of_tree(root->right));
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

  cout << "Height of Binary tree: " << height_of_tree(root) << endl;

  return 0;
}
