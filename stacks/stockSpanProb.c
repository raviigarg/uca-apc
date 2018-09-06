#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  int *arr;
  int top;
} STK;

void initialize(STK *mem, int x) {
  mem->arr = (int *)malloc(sizeof(int) * x);
  mem->top = -1;
}

int isEmpty(STK *s) {
  if (s->top == -1)
    return 1;
  return 0;
}

int isFull(STK *s, int size) {
  if (s->top == size)
    return 1;
  return 0;
}

void push(STK *s, int d, int size) {
  if (isFull(s, size))
    printf("Stack is full, can not insert more values");
  else
    s->top++;
  s->arr[s->top] = d;
}

void pop(STK *s) {
  if (isEmpty(s))
    printf("Stack is already empty");
  else
    s->top--;
}

int top(STK *s) {
  if (isEmpty(s))
    printf("Stack is empty");
  else
    return s->arr[s->top];
}

void checkMax(int *buildHeights, int size) {
  STK *s = (STK *)malloc(sizeof(STK));
  initialize(s, size);
  int count = 1;
  int *span = (int *)malloc(sizeof(int) * size);
  span[0] = count;
  push(s, 0, size);
  for (int i = 1; i < size; i++) {
    while (!isEmpty(s) && buildHeights[top(s)] <= buildHeights[i])
      pop(s);

    span[i] = isEmpty(s) ? i + 1 : i - top(s);

    push(s, i, size);
  }

  for (int i = 0; i < size; i++) {
    printf("%d\t", span[i]);
  }

  printf("\n");
}

int main() {

  int buildHeights[] = {100, 80, 60, 70, 60, 75, 85};

  int size = sizeof(buildHeights) / sizeof(buildHeights[0]);

  checkMax(buildHeights, size);

  return 0;
}
