#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *link;
} node;

node *create_new_node() {
  node *nn = (node *)malloc(sizeof(node));
  return nn;
}

void push(node **h, int data) {
  node *nn = create_new_node();
  nn->data = data;
  nn->link = NULL;

  if (*h == NULL) {
    *h = nn;
  } else {
    node *curr = *h;
    while (curr->link)
      curr = curr->link;
    curr->link = nn;
  }
}

void print_ll(node *h) {
  node *curr = h;
  while (curr) {
    printf("%d\t", curr->data);
    curr = curr->link;
  }
}

void reverse(node **h) {
  node *curr = *h;
  node *prev = NULL;
  node *next;

  while (curr) {
    next = curr->link;
    curr->link = prev;
    prev = curr;
    curr = next;
  }
  *h = prev;
}

int compare_ll(node *first, node *second) {
  node *curr1 = first, *curr2 = second;
  while (curr1 && curr2) {
    if (curr1->data != curr2->data) {
      return 0;
    }

    curr1 = curr1->link;
    curr2 = curr2->link;
  }

  if (curr1 == NULL && curr2 == NULL)
    return 1;
  else
    return 0;
}

int check_palindrome(node *h) {
  node *fast = h, *slow = h;
  node *prev_of_slow, *second_half;
  // node *mid;
  int res = 1;
  if (h != NULL && h->link != NULL) {
    while (fast && fast->link) {
      fast = fast->link->link;
      prev_of_slow = slow;
      slow = slow->link;
    }

    if (fast) {
      // mid = slow;
      slow = slow->link;
    }

    second_half = slow;
    prev_of_slow->link = NULL;
    reverse(&second_half);
    res = compare_ll(h, second_half);
  }
  return res;
}

int main() {
  node *head = NULL;
  printf("Enter no of nodes: ");
  int n;
  scanf("%d", &n);
  printf("Enter data: ");
  for (int i = 0; i < n; i++) {
    int d;
    scanf("%d", &d);
    push(&head, d);
  }
  // printf("Linked List before reverse:\n");
  // print_ll(head);
  reverse(&head);
  // printf("Linked List after reverse:\n");
  // print_ll(head);

  if (check_palindrome(head)) {
    printf("Linked List is palindrome.");
  } else {
    printf("Linked List is not palindrome.");
  }
  return 0;
}
