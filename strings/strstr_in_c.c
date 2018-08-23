#include<stdio.h>
#include<stdlib.h>
#include <string.h>

char* find_substr(char *str, char *substr) {
	int i, j, flag = 0;

	for(i = 0; str[i] != '\0'; i++) {
		int k = 0;
		flag = 0;
		if(str[i] == substr[k]) {
			for(j = i; substr[k] != '\0'; j++) {
				if(str[j] != substr[k]) {
					flag = 1;
					break;
				}
				k++;
			}
			if(flag == 0) {
				return (str+i);
			}
		}	

	}
	return NULL;
}

int main() {
	char s1[] = "Hello World world";
	char s2[] = "wor";
	printf("%s", find_substr(s1, s2));
	return 0;
}
