//swap all two consecutive bits of a number  

#include<stdio.h>
#include<stdlib.h>

int swapBits(int n) {
	return ((n>>1) & 0x55555555) | ((n<<1) & 0xAAAAAAAA);
}

int main() {
	int a;
	scanf("%d",&a);
	int n = swapBits(a);
	printf("%d", n);
}