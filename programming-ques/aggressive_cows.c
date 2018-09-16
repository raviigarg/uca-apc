/* Assign cows to the stalls,
   -such that the minimum distance between any two of them is as large as
   possible. -What is the largest minimum distance?
   -https://www.spoj.com/problems/AGGRCOW/
*/

#include <stdio.h>
#include <stdlib.h>

int comp1(const void *x, const void *y) { return (*(int *)x - *(int *)y); }

int func(int *a, int n, int mid, int c) {
  int cows = 1, diff = 0;
  for (int i = 1; i < n; i++) {
    diff = diff + (a[i] - a[i - 1]);
    if (diff >= mid) {
      cows++;
      diff = 0;
    }
    if (cows >= c)
      return 1;
  }
  return 0;
}

int minDist(int *a, int n, int c) {
  int left = 0;
  int right = a[n - 1] - a[0];
  int max = -1;
  while (left < right) {
    int mid = (left + right) / 2;
    if (func(a, n, mid, c)) {
      if (max < mid) {
        max = mid;
      }
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return max;
}

int main() {
  int test;
  scanf("%d", &test);
  for (int i = 0; i < test; i++) {
    int n, c;
    scanf("%d%d", &n, &c);
    int *ptr = (int *)malloc(sizeof(int) * n);
    for (int j = 0; j < n; j++) {
      scanf("%d", &ptr[j]);
    }

    qsort(ptr, n, sizeof(int), comp1);

    int mindis = minDist(ptr, n, c);
    printf("%d\n", mindis);
  }
}
