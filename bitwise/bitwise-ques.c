#include<stdio.h>
#include<stdlib.h>

//function to do bitwise AND without using & operator
int bitAnd(int x,int y){
    return ~((~x)|(~y));
}

//function to do bitwise XOR without using ^ operator 
int bitXor(int x,int y) {
    //return ~(x & y) & ~(~x & ~y);
    return ~(~(x&(~y))&(~((~x)&y)));
}

//function to return -1 when no is negative, 0 when no is 0,
//and 1 when it is positive 
int sign(int x) {
    //return (x >> 31) | (!(!x));
    return (x>>31)+(~((~x+1)>>31)+1);
}

//function to do logical shift
int logicalShift(int x, int n) {
    //Use mask to mask out the leading bits.
    int mask = ~(((1 << 31) >> n) << 1);
    return (x >> n) & mask;
}

//function to get nth byte
int getByte(int x, int n){
      return (x >> (n << 3) & (0xFF));
}

//implementation of bang operator
int bang(int x){
   int tmp = (((~x + 1) | x) >> 31);
    return tmp + 1;
}

//function to implement ternary operator
int conditional(int x, int y, int z) {
    int a = (x >> 31) | ((~x + 1) >> 31);
    return ((a & y) + (~a & z));
}

//function to check given no is power of 2 or not
int powerOf2(int x) {
    // int sign = !(x >> 31);
    // return (!!x) & sign & !((x + ~1 + 1) & x);
    return !(x&(((~x)+1)<<1));
}

int main(){
    
    printf("Bitwise And = %d\n",bitAnd(7,5));
  
    printf("Bitwise Xor = %d\n",bitXor(7,4));

    printf("Signed Bit = %d\n", sign(-64));

    printf("Logical shift = %d\n", logicalShift(-5,2));

    printf("Get Byte = %d\n", getByte(10,2));
    
    printf("Bang = %d\n",bang(1));

    printf("Conditional = %d\n",conditional(5, 2, 6));

    printf("Power of 2 = %d\n",powerOf2(65536));
    
    return 0;
}