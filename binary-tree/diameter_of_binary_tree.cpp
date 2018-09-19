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

int getDia(BTree *root, int &dia) {

  if (root == NULL)
    return 0;

  int lheight = getDia(root->left, dia);
  int rheight = getDia(root->right, dia);

  int max_dia = lheight + rheight + 1;

  dia = max(dia, max_dia);

  return max(lheight, rheight) + 1;
}

int diameter_of_tree(BTree *root) {

  if (root == NULL)
    return 0;

  int dia = 0;
  getDia(root, dia);
  return dia;
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

  cout << "Diameter of Binary Tree: " << diameter_of_tree(root) << endl;

  return 0;
}
