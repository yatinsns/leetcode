#include <stdio.h>
#include <stdlib.h>

int reverse(int x) {
    int rev = 0;
    int num = abs(x);
    while (num > 0) {
        int prev_rev = rev;
        rev = (rev * 10) + (num % 10);
        int temp =  
        printf("rev: %d prev: %d temp: %d\n", rev, prev_rev, temp);
        if ((rev - (num % 10)) / 10 != prev_rev){
            // overflow case
            return 0;
        }
        num = num / 10;
    }
    
    return x > 0 ? rev : -rev;
}

int main(int argc, char *argv[]) {
  int num = 1534236469;
  printf("num: %d", num);
  int result = reverse(num);
  printf("result: %d", result);
  return 0;
}
