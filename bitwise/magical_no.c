#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int magical_no(int a) {
	int magic_n = 0, p = 1;
	
	for(int i = 0; i < 32; i++) {
		p *= 5;
		if(a & (1<<i)) {
			magic_n += p;
		}
	}
	return magic_n;
}

int main() {

	int n;
	printf("Enter no : ");
	scanf("%d", &n);

	printf("Magical number: %d", magical_no(n));

	return 0;
}