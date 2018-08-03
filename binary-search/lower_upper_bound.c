#include<stdio.h>
#include<stdlib.h>

int lower_bound(int *a, int left, int right,  int s) {
    //using recursion
    // if(left==right) {
    //         return left;
    //     }
    // while(left<right) {
    //     int mid = (left+right)/2;
    //     if(a[mid]>=s) {
    //         return lower_bound(a, left, mid, s);
    //     }
    //     else if(a[mid]>s) {
    //         right = mid-1;
    //     }else {
    //         left = mid+1;
    //     }
    // }

    while(left<right) {
        int mid = (left+right)/2;
        if(s<=a[mid]){
            right = mid;
        }else {
            left = mid + 1;
        }
    }
    return left;
}

int upper_bound(int *a, int left, int right,  int s) {
     while(left<right)  {
        int mid = (left+right)/2;
        if(s>=a[mid]){
            left = mid+1;
        }else {
            right = mid;
        }
    }
    return left;
}

int main(){
    int n=14;
    int arr[] = {1,1,2,2,2,3,3,3,5,5,5,6,6,6};
    int lo = lower_bound(arr, 0, n-1, 2);
    printf("lower Bound: %d\n", lo);
    int up = upper_bound(arr, 0, n, 2);
    printf("Upper Bound: %d", up);
    return 0;
}