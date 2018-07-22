//Check double and float

#include<stdio.h>
#include<stdlib.h>

int main(){

    double x = 5.5;

    unsigned char* ch1 = (char*)(&x);
    printf("For double - ");
    for(int i =0; i< 8; i++) {
        printf("%d", *(ch1+i));
    }

    float y = 5.5f;

    unsigned char* ch2 = (char*)(&y);
    printf("\nFor float - ");
    for(int i =0; i< 4; i++) {
        printf("%d", *(ch2+i));
    }
    
    return 0;
}