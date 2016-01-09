#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *longestPalindrome(char *s) {
  char *result = NULL;
  int length = strlen(s);

  int isPalindrome[1000][1000];

  int resultLower = -1, resultUpper = -1, maxLength = 0;
  for (int diff = 0; diff < length ; diff++) {
    for (int i = 0 ; i + diff < length; i++) {
      int j = i + diff;
      if (s[i] == s[j]) {
        int isInnerStringPalindrome = 1;
        if ((i + 1) < (j - 1)) {
          isInnerStringPalindrome = isPalindrome[i + 1][j - 1];
        }
       
        if (isInnerStringPalindrome) {
          int probableMaxLength = j - i + 1;
          if (probableMaxLength > maxLength) {
            maxLength = probableMaxLength;
            resultLower = i;
            resultUpper = j;
          }
          isPalindrome[i][j] = 1;
        }
      } else {
        isPalindrome[i][j] = 0;
      }
    }
  }

  printf("maxLength  : %d (%d, %d)", maxLength, resultLower, resultUpper);
  if (maxLength != 0) {
    result = malloc((maxLength + 1) * sizeof(char));
    int i;
    for (i = resultLower; i <= resultUpper; i++) {
      result[i - resultLower] = s[i];
    }
    result[i - resultLower] = '\0';
  } else {
    result = malloc(1 * sizeof(char));
    result[0] = '\0';
  }
  return result;
}

int main(int argc, char *argv[]) {
  char *input = "aaaabaaa";
  char *result = longestPalindrome(input);
  printf("result: %s", result);

  return 0;
}
