#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
    int length = strlen(s);
    char *result = malloc((length + 1) * sizeof(char));
    int currentIndex = 0;
    
    
    int step1 = (numRows - 1) * 2, step2 = 0;
    if (numRows == 1) {
        step1 = 1;
    }
    for (int i = 1; i <= numRows; i++) {
        int startIndex = i - 1;
        int dir = 0;
        
        while (startIndex < length) {
            result[currentIndex] = s[startIndex];
            currentIndex++;

            if (dir == 0) {
              startIndex += (step1 == 0 ? step2 : step1);
              dir = 1;
            } else {
              startIndex += (step2 == 0 ? step1 : step2);
              dir = 0;
            }
        }
        
        step1 -= 2;
        step2 += 2;
    }
    
    result[currentIndex] = '\0';
    
    return result;
}

int main() {
    //printf("result : %s", convert("PAYPALISHIRING", 3));

    printf("result : %s", convert("A", 1));
    return 0;
}
