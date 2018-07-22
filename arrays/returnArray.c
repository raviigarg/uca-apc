//different ways of returning array

#include <stdio.h>
#include <stdlib.h>

int* function1(int *x) {
    static int arr[] = {1,2,3,4,5}; // must be static
    *x = 5;
    return arr;
}

int (*function2(int *x))[5] {
    static int arr[] = {1,2,3,4,5};
    *x = 5;
    return &arr;
}

int main() {
    int n;
    int *a = function1(&n);
    for(int i = 0; i<n ;i++) {
        printf("%d\n", *(a+i));
    }

    int (*b)[5] = function2(&n);
    for(int i = 0; i<n ;i++) {
        printf("%d\n", *(*b+i));
    }
    return 0;
}