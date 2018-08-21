#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void longest_palindrome_substr(char *str) {
	int max_len = 1;
	int left = 0, right = 0, start = 0;
	int len = strlen(str);
	for(int i = 1; i < len; i++) {
		//if longest palindrome substring is even
		left = i-1;
		right = i;
		while(left >= 0 && right < len && str[left] == str[right]) {
			if(right - left + 1 > max_len) {
				start = left;
				max_len = right - left + 1; 
			}

			left--;
			right++;
		}

		//if longest palindrome substring is odd
		left = i-1;
		right = i+1;
		while(left >= 0 && right < len && str[left] == str[right]) {
			if(right - left + 1 > max_len) {
				start = left;
				max_len = right - left + 1; 
			}

			left--;
			right++;
		}
	}

	for(int i = start; i < start + max_len; i++) {
		printf("%c", str[i]);
	}

}

int main() {
	char str[] = "banana";
	longest_palindrome_substr(str);
	return 0;	
}