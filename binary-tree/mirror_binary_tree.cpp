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

// Level order traversal
void levelorderTraversal(BTree *root) {
  queue<BTree *> q;
  q.push(root);
  while (!q.empty()) {
    BTree *node = q.front();
    q.pop();
    cout << node->data << " ";
    if (node->left) {
      q.push(node->left);
    }

    if (node->right) {
      q.push(node->right);
    }
  }
}

BTree *make_mirror_tree(BTree *root) {
  if (root == NULL)
    return NULL;
  else {
    BTree *nn = (BTree *)malloc(sizeof(BTree));
    nn->data = root->data;
    nn->right = make_mirror_tree(root->left);
    nn->left = make_mirror_tree(root->right);
    return nn;
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
    cin >> d;
    root = make_binary_tree(root, d);
  }

  cout << "Level order traversal original tree:" << endl;
  levelorderTraversal(root);
  cout << endl;
  root = make_mirror_tree(root);
  cout << "Level order traversal mirror tree:" << endl;
  levelorderTraversal(root);
  cout << endl;

  return 0;
}
