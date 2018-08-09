//Forest Gathering - Codechef
//https://www.codechef.com/problems/FORESTGA
  
#include <stdio.h>
#include <stdlib.h>

int func(long long int *H,long long int *R,long long int n,long long int mid,long long int l,long long int w) {
	long long int sum = 0;
	for(long long int i = 0; i < n; i++) {
		long long int a = H[i] + R[i]*mid;
		if(a >= l) {
			sum += a;
			if(sum>=w)
				return 1;
		}
	}
	return 0;
}

int main() {
	int sum = 0;
	long long int N, W, L;
	scanf("%lld%lld%lld", &N, &W,&L);
	long long int *H = (long long int*) malloc(sizeof(long long int)*N);
	long long int *R = (long long int*) malloc(sizeof(long long int)*N);
	for(long int i = 0; i < N; i++) {
		scanf(" %lld%lld", &H[i], &R[i]);
	}

	long long int left = 0;
	long long int right = W;

	while(left<right) {
		long long int mid = (left+right)/2;
		if(func(H, R, N, mid, L, W)){
			right = mid;
		}else {
			left = mid+1;
		}
	}
	printf("%lld", left);
	return 0;
}