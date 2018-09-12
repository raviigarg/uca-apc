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

void swap_nodes(node **head) {
  node *first = *head, *second;
  node **common = head;
  if (first)
    second = first->next;
  while (first && second) {
    first->next = second->next;
    second->next = first;
    *common = second;
    common = &(first->next);
    first = first->next;
    if (first)
      second = first->next;
  }
}

void print_list(node *head) {
  node *cursor = head;
  while (cursor) {
    printf("%d\n", cursor->data);
    cursor = cursor->next;
  }
}

int main() {
  node *head = NULL;
  for (int i = 1; i <= 7; i++) {
    push(&head, i);
  }
  print_list(head);
  printf("After swap\n");
  swap_nodes(&head);
  print_list(head);
  return 0;
}
