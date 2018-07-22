//MAaximum of three numbers using ternary operator 

#include<stdio.h>
#include<stdlib.h>

int main() {
    int a = 3, b = 4, c =5;
    int max;
    max = a > b ? (a > c ? a : c) : (b > c ? b : c);
    printf("Max is = %d", c);
}