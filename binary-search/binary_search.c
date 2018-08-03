// program to iterative Binary Search
#include <stdio.h>

int binarySearch(int arr[], int left, int right, int s) {
    while (left <= right)
    {
        int mid = (left + right)/2;
        if (arr[mid] == s)
            return mid;

        if (arr[mid] < s)
            left = mid + 1;

        else
            right = mid - 1;
    }
    return -1;
}

int main(void)
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int s = 10;
    int result = binarySearch(arr, 0, n-1, s);
    printf("Index of %d is %d\n", s, result);
    return 0;
}
