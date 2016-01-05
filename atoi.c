#include <stdio.h>
#include <ctype.h>
#include <limits.h>

int myAtoi(char* str) {
    char *ptr = str;
    int result = 0;
    
    while (isspace(*ptr)) {
        ptr++;
    }
    
    int negative = 0;
    switch (*ptr) {
        case '-' : negative = 1; ptr++; break;
        case '+' : negative = 0; ptr++; break;
    }
    
    int is_overflowed = 0;
    while (*ptr != '\0' && isdigit(*ptr)) {
        int prev_result = result;
        result = result * 10 + (*ptr - '0');
        printf("result: %d  prev: %d\n", result, prev_result);
        if (prev_result > 214748364) {
            is_overflowed = 1;
            break;
        } else if (prev_result == 214748364 && (*ptr - '0') > 7){
            is_overflowed = 1;
            break;
        }
        ptr++;
    }
    
    if (is_overflowed) {
        return negative ? INT_MIN : INT_MAX;
    } else {
        return negative ? -result : result;
    }
}

int main(int argc, char *argv[]) {
  char str[] = "2147483648";
  int result = myAtoi(str);
  printf("str: %s  result: %d", str, result);
  return 0;
}
