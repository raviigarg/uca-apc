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

// In order traversal using recursion - left root right
void inorderTraversal(BTree *root) {
  if (root == NULL)
    return;
  inorderTraversal(root->left);
  printf("%d\t", root->data);
  inorderTraversal(root->right);
}

// Pre order traversal using recursion - root left right
void preorderTraversal(BTree *root) {
  if (root == NULL)
    return;
  printf("%d\t", root->data);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

// Post order traversal uaing recursion - left right root
void postorderTraversal(BTree *root) {
  if (root == NULL)
    return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d\t", root->data);
}

// Level order traversal
void levelorderTraversal(BTree *root) {
  queue<BTree *> q;
  q.push(root);
  while (!q.empty()) {
    BTree *node = q.front();
    q.pop();
    printf("%d\t", node->data);
    if (node->left) {
      q.push(node->left);
    }

    if (node->right) {
      q.push(node->right);
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

  printf("In Order Traversal is:\n");
  inorderTraversal(root);
  printf("\nPre Order Traversal is:\n");
  preorderTraversal(root);
  printf("\nPost Order Traversal is:\n");
  postorderTraversal(root);
  printf("\nLevel Order Traversal is:\n");
  levelorderTraversal(root);
  printf("\n");

  return 0;
}
