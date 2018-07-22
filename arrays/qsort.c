//use of qsort function/*  */

#include<stdio.h>
#include<stdlib.h>

//In increasing order
int comp1(void *x, void *y) {
    return *((int*)x) - *((int*)y);
}

//In decreasing order
int comp2(void *x, void *y) {
    return *((int*)y) - *((int*)x);
}

int main(){
    int a[6] = {4,6,2,1,8,9};
    qsort(a, 6, sizeof(int), comp2);
    for(int i = 0; i<6; i++){
        printf("%d\t",a[i]);
    }
}