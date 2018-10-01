#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_substr(char *str, char *substr) {
  int len1 = strlen(str);
  int len2 = strlen(substr);
  int i = 0, j = 1;
  int start = -1;
  int *lps = (int *)malloc(sizeof(int) * len2);
  lps[0] = 0;
  while (i < len2 && j < len2) {
    if (substr[i] == substr[j]) {
      lps[j] = i + 1;
      i++;
      j++;
    } else {
      if (i == 0) {
        lps[j] = 0;
        j++;
      } else {
        i = lps[i - 1];
      }
    }
  }

  i = 0;
  j = 0;

  while (j < len1 && i < len2) {
    if (str[j] == substr[i]) {
      i++;
      j++;
    } else {
      if (i == 0) {
        j++;
      } else {
        i = lps[i - 1];
      }
    }
  }
  if (i == len2) {
    start = j - len2;
  }

  // printf("%d", start);
  return start;
}

int main() {
  char s1[] = "hello world WoRld hello";
  char s2[30] = "Rldf";
  // find_substr(s1, s2);
  printf("%d\n", find_substr(s1, s2));
  return 0;
}
