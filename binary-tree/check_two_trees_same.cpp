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

int is_identical_trees(BTree *root1, BTree *root2) {
  if (root1 && root2) {
    if (root1->data != root2->data)
      return 0;

    return (is_identical_trees(root1->left, root2->left) &&
            is_identical_trees(root1->right, root2->right));
  }

  if (root1 == NULL && root2 == NULL)
    return 1;
  else
    return 0;
}

int main() {

  BTree *root1 = NULL;
  BTree *root2 = NULL;
  int n;
  printf("Enter no of nodes: ");
  scanf("%d", &n);
  printf("Enter data1:\n");
  for (int i = 0; i < n; i++) {
    int d;
    scanf("%d", &d);
    root1 = make_binary_tree(root1, d);
  }
  printf("Enter data2: \n");
  for (int i = 0; i < n; i++) {
    int d;
    scanf("%d", &d);
    root2 = make_binary_tree(root2, d);
  }

  if (is_identical_trees(root1, root2))
    printf("Trees are identical\n");
  else
    printf("Trees are not identical\n");

  return 0;
}
