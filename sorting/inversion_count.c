#include <stdio.h>
#include <stdlib.h>

int merge(int arr[], int aux[], int left, int mid, int right) {

  int k = left, i = left, j = mid + 1;
  int inv_count = 0;

  while (i <= mid && j <= right) {
    if (arr[i] <= arr[j]) {
      aux[k++] = arr[i++];
    } else {
      aux[k++] = arr[j++];
      inv_count += (mid - i + 1);
    }
  }

  while (i <= mid)
    aux[k++] = arr[i++];

  for (int i = left; i <= right; i++) {
    arr[i] = aux[i];
  }

  return inv_count;
}

int merge_sort(int arr[], int aux[], int left, int right) {
  if (left == right)
    return 0;

  int mid = (left + right) / 2;
  int inv_count = 0;

  inv_count += merge_sort(arr, aux, left, mid);

  inv_count += merge_sort(arr, aux, mid + 1, right);

  inv_count += merge(arr, aux, left, mid, right);

  return inv_count;
}

int main() {
  int arr[] = {1, 20, 6, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  int aux[n];

  for (int i = 0; i < n; i++) {
    aux[i] = arr[i];
  }

  int inv_count = merge_sort(arr, aux, 0, n - 1);

  printf("Inversion cont is %d\n", inv_count);
  return 0;
}
