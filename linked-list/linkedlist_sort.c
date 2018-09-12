#include <stdio.h>
#include <stdlib.h>

struct listnode {
  int data;
  struct listnode *link;
};

void push(struct listnode **h, int data) {
  struct listnode *nn = (struct listnode *)malloc(sizeof(struct listnode));
  nn->data = data;
  if (*h == NULL) {
    *h = nn;
  } else {
    struct listnode *curr = *h;
    while (curr->link != NULL)
      curr = curr->link;

    curr->link = nn;
  }
  nn->link = NULL;
}

void print(struct listnode *h) {
  struct listnode *curr = h;
  while (curr) {
    printf("%d\t", curr->data);
    curr = curr->link;
  }
  printf("\n");
}

void mid_divide(struct listnode *start, struct listnode **left,
                struct listnode **right) {
  struct listnode *fast;
  struct listnode *slow;

  slow = start;
  fast = start->link;

  while (fast != NULL) {
    fast = fast->link;
    if (fast != NULL) {
      slow = slow->link;
      fast = fast->link;
    }
  }

  *left = start;
  *right = slow->link;
  slow->link = NULL;
}

struct listnode *sorted_merge(struct listnode *left, struct listnode *right) {
  struct listnode *res = NULL;

  if (left == NULL) {
    return right;
  } else if (right == NULL) {
    return left;
  }

  if (left->data <= right->data) {
    res = left;
    res->link = sorted_merge(left->link, right);
  } else {
    res = right;
    res->link = sorted_merge(right->link, left);
  }

  return res;
}

void merge_sort(struct listnode **h) {
  struct listnode *curr = *h;
  struct listnode *left, *right;

  if (curr == NULL || curr->link == NULL) {
    return;
  }

  mid_divide(curr, &left, &right);

  merge_sort(&left);
  merge_sort(&right);

  *h = sorted_merge(left, right);
}

int main() {
  struct listnode *head = NULL;
  printf("Enter no of nodes: ");
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int data;
    scanf("%d", &data);
    push(&head, data);
  }
  printf("Before Sorting linked list:\n");
  print(head);
  merge_sort(&head);
  printf("After Sorting linked list:\n");
  print(head);
}
