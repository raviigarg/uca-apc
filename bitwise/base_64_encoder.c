#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void find_encode(char *input) {
  int len = strlen(input);
  printf("%d\n", len);
  char char_set[64] =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

  int res_len = 4 * (len + 2) / 3;
  char *res = (char *)malloc(sizeof(char) * (res_len + 1));

  int index, no_bits, padding = 0, val, count, temp;
  int i = 0, j, k = 0;

  for (i = 0; i < len; i = i + 3) {
    val = 0, count = 0, no_bits = 0;

    for (j = i; j < len && j <= i + 2; j++) {
      val = val << 8;

      val = val | input[j];

      count++;
    }

    no_bits = count * 8;
    padding = no_bits % 3;

    while (no_bits != 0) {
      if (no_bits >= 6) {
        temp = no_bits - 6;
        index = (val >> temp) & 63;
        no_bits -= 6;
      } else {
        temp = 6 - no_bits;

        index = (val << temp) & 63;
        no_bits = 0;
      }

      res[k++] = char_set[index];
    }
  }

  for (i = 0; i < padding; i++) {
    res[k++] = '=';
  }

  res[k] = '\0';
  printf("%s", res);
}

int main() {
  char input[] = "MENON";
  find_encode(input);
  return 0;
}
