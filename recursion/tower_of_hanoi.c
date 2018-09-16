#include <stdio.h>
#include <stdlib.h>

int tower_of_hanoi(int n, char beg, char aux, char end) {
  if (n == 1) {
    return 1;
  } else {
    return tower_of_hanoi((n - 1), beg, end, aux) +
           tower_of_hanoi(1, beg, aux, end) +
           tower_of_hanoi((n - 1), aux, beg, end);
  }
}

int main() {
  printf("Enter the no slides: ");
  int s;
  scanf("%d", &s);
  int num = tower_of_hanoi(s, 'A', 'B', 'C');
  printf("Flip required: %d\n", num);
  return 0;
}
