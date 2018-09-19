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

// Morris n order traversal using recursion - left root right
void morris_inorderTraversal(BTree *root) {
  BTree *curr, *pre;

  if (root == NULL)
    return;

  curr = root;
  while (curr != NULL) {
    if (curr->left == NULL) {
      cout << curr->data << " ";
      curr = curr->right;
    }

    else {
      pre = curr->left;
      while (pre->right != NULL && pre->right != curr)
        pre = pre->right;

      if (pre->right == NULL) {
        pre->right = curr;
        curr = curr->left;
      } else {
        pre->right = NULL;
        cout << curr->data << " ";
        curr = curr->right;
      }
    }
  }
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

  printf("Morris in Order Traversal is:\n");
  morris_inorderTraversal(root);
  cout << endl;

  return 0;
}
