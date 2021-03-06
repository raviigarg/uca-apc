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

void create_loop(node **head) {

  node *cursor1 = *head;
  node *cursor2 = *head;
  while (cursor1->next) {
    cursor1 = cursor1->next;
  }

  for (int i = 0; i < 2; i++) {
    cursor2 = cursor2->next;
  }
  cursor1->next = cursor2;
}

int detect_loop(node *head) {
  int flag = 0;
  node *slow = head, *fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (fast == slow) {
      flag = 1;
      break;
    }
  }
  return flag;
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
  for (int i = 1; i <= 6; i++) {
    push(&head, i);
  }
  create_loop(&head);
  // print_list(head);
  int detect = detect_loop(head);
  if (detect == 1) {
    printf("Loop present\n");
  } else {
    printf("Loop not exists\n");
  }
  return 0;
}
