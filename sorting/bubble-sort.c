#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int *a, int n) {
    int temp, flag = 0;
    for(int i = 0; i < n-1; i++) {
        flag = 0;
        for(int j = 0; j < n-1-i; j++) {
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
    for(int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
}

int main() {
    int arr[] = {5, 3, 9, 8, 1, 2};
    int size = sizeof(arr)/ sizeof(arr[0]);
    bubbleSort(arr, size);
}