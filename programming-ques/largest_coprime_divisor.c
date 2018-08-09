/*
 -Largest Coprime Divisor
 -Given two positive numbers A and B. Find the maximum valued integer X such that:

 -X divides A i.e. A % X = 0
 -X and B are co-prime i.e. gcd(X, B) = 1
*/

#include<stdio.h>
#include<stdlib.h>

int gcd(int x, int y){
	if(y==0)
		return x;
	else
		return gcd(y, x%y);
}

int main() {
	int a, b;
	scanf("%d%d",&a,&b);
}