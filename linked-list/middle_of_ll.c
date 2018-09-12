#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

node *createNewNode() {
  node *nn = (node *)malloc(sizeof(node));
  return nn;
}

void push(node **h, int d) {
  node *nn = createNewNode();
  nn->data = d;
  nn->next = NULL;
  if (*h == NULL) {
    *h = nn;
  } else {
    node *curr = *h;
    while (curr->next) {
      curr = curr->next;
    }
    curr->next = nn;
  }
}

int middle(node *head) {
  node *fast = head, *slow = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow->data;
}

int main() {
  node *head = NULL;
  for (int i = 1; i < 11; i++) {
    push(&head, i);
  }
  int mid = middle(head);
  printf("Middle Node is: %d\n", mid);
}
