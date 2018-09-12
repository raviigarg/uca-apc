#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  int data;
  struct node *link;
} * start, *visit;

void append(struct node **q, int val) {
  struct node *temp;
  temp = *q;
  if (*q == NULL) {
    *q = (struct node *)malloc(sizeof(struct node));
    temp = *q;
  } else {
    while (temp->link != NULL) {
      temp = temp->link;
    }

    temp->link = (struct node *)malloc(sizeof(struct node));
    temp = temp->link;
  }

  temp->data = val;
  temp->link = NULL;
}

void getdata() {
  int val, n;
  char ch;
  struct node *newnode;

  newnode = NULL;

  do {
    printf("Enter a value: ");
    scanf("%d", &val);

    append(&newnode, val);

    printf("Any More Nodes(Y/N):");
    scanf(" %c", &ch);
  } while (ch == 'y' || ch == 'Y');

  start = newnode;
}

void displaylist() {
  visit = start;

  while (visit != NULL) {
    printf("%d\t", visit->data);
    visit = visit->link;
  }
}

void selection_sort() {
  struct node *p, *q, *r, *s, *temp;

  p = r = start;
  while (p->link != NULL) {
    s = q = p->link;
    while (q != NULL) {
      if (p->data > q->data) {
        if (p->link == q) { // adjacent nodes
          if (p == start) {
            p->link = q->link;
            q->link = p;

            temp = p;
            p = q;
            q = temp;

            start = p;
            r = p;
            s = q;
            q = q->link;
          } else {
            p->link = q->link;
            q->link = p;
            r->link = q;

            temp = p;
            p = q;
            q = temp;

            s = q;
            q = q->link;
          }
        } else {
          if (p == start) {
            temp = q->link;
            q->link = p->link;
            p->link = temp;

            s->link = p;

            temp = p;
            p = q;
            q = temp;

            s = q;
            q = q->link;
            start = p;
          } else {
            temp = q->link;
            q->link = p->link;
            p->link = temp;

            r->link = q;
            s->link = p;

            temp = p;
            p = q;
            q = temp;

            s = q;
            q = q->link;
          }
        }
      } else {
        s = q;
        q = q->link;
      }
    }
    r = p;
    p = p->link;
  }
}

void bubble_sort() {
  struct node *p, *q, *r, *s, *temp;
  s = NULL;
  while (s != start->link) {
    r = p = start;
    q = p->link;
    while (p != s) {
      if (p->data > q->data) {
        if (p == start) {
          temp = q->link;
          q->link = p;
          p->link = temp;

          start = q;
          r = q;
        } else {
          temp = q->link;
          q->link = p;
          p->link = temp;

          r->link = q;
          r = q;
        }
      } else {
        r = p;
        p = p->link;
      }
      q = p->link;
      if (q == s)
        s = p;
    }
  }
}

int main() {

  getdata();
  printf("\n\nLinked List Before Sorting:\n");
  displaylist();

  selection_sort();
  printf("\nLinked List After selection sort\n");
  displaylist();

  printf("\n");
  getdata();
  printf("\n\nLinked List Before Sorting:\n");
  displaylist();

  bubble_sort();
  printf("\nLinked List After bubble sort\n");
  displaylist();
  return 0;
}
