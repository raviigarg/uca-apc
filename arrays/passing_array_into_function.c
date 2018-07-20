//Diiferent menthods of passing array to functions
#include<stdio.h>
#include<stdlib.h>

void func1(int x, int y, int (*a)[x][y]) {
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            printf("%d\t", *(*(*a+i)+j));
        }
        printf("\n");
    }
}

void func2(int x, int y, int (*a)[y]) {
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            printf("%d\t", *(*(a+i)+j));
        }
        printf("\n");
    }
}

void func3(int x,int y, int *a){
     for(int i = 0; i < x*y; i++) {
            printf("%d\t", *(a+i));
        printf("\n");
    }
}

int main() {
    int arr[3][3] = {1,2,3,4,5,6,7,8,9};
    //passing whole array
    func1(3,3,&arr);
    //passing first row of 2-D array 
    func2(3,3,arr);
    //passing address of first element of first row of 2-D array
    func3(3,3,*arr);
    return 0;
}