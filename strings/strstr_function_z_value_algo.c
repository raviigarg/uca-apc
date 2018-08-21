#include<stdio.h>
#include<stdlib.h>
#include <string.h>

char *find_substr(char *str, char *substr) {
	int x = strlen(str);
	int y = strlen(substr);
	//printf("length of str: %d, length of substr: %d\n", x, y);
	substr = strcat(substr,"$");
	substr = strcat(substr, str);


	int len = strlen(substr);


	int *z = (int *)malloc(sizeof(int)*len);
	int l = 0, r = 0;

	for(int i = 1; i < len; i++) {
		if(i > r) {
			l = i;
			r = i;
			while(r < len && substr[r-l] == substr[r])
				r++;
			z[i]= r - l;
			r--;
		} else {
			if(z[i-l] <  r-i+1)
				z[i] = z[i-l];
			else {
			l = i;
			while(r < len && substr[r-l] == substr[r])
				r++;
			z[i]= r - l;
			r--;
			}
		}
	}
	for(int i = 0; i < len; i++) {
		if(z[i]==y) {
			return str+(i-y-1);
		}
	}
	printf("\n");
	return NULL;
	
}

int main() {
	char s1[] = "Hello World world";
	char s2[30] = "wor";
	printf("%s\n", find_substr(s1, s2));
	return 0;
}