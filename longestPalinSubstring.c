#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s) {
    int i, length = strlen(s);
    int low_index = -1, high_index = -1, max_length = 0;

    for (i = 0; i < length; i++) {
        int l, r, current_length;
        
        // Assume i to be center for odd palindrome
        l = i - 1;
        r = i + 1;
        current_length = 1;
        while (l >= 0 && r < length) {
            if (s[l] == s[r]) {
                current_length += 2;
                l = l - 1;
                r = r + 1;
            } else {
                break;
            }
        }
        
        if (current_length > max_length) {
            max_length = current_length;
            low_index = l + 1;
            high_index = r - 1;
        }
        
        // Assume i and (i - 1) to be center for even palindrome
        if (i > 0 && s[i - 1] == s[i]) {
            l = i - 2;
            r = i + 1;
            current_length = 2;
            
            while (l >= 0 && r < length) {
                if (s[l] == s[r]) {
                    current_length += 2;
                    l = l - 1;
                    r = r + 1;
                } else {
                    break;
                }
            }
            
            if (current_length > max_length) {
                max_length = current_length;
                low_index = l + 1;
                high_index = r - 1;
            }
        }
    }
    
    char *result = (char *)malloc((max_length + 1) * sizeof(char));
    
    if (low_index != -1 && high_index != -1) {
        for (i = low_index; i <= high_index; i++) {
            result[i - low_index] = s[i];
        }
        result[i - low_index] = '\0';
    } else {
        result[0] = '\0';
    }
    
    return result;    
}

int main(int argc, char *argv[]) {
  char *input = "daomdukomcayjwgmmetypncdeixarhbectjcwftjjtwjrctixtrsehegwlfotpljeeqhntacfihecdjysgfmxxbjfeskvvfqdoedfxriujnoeteleftsjgdsagqvcgcdjbxgmguunhbjxyajutohgbdwqtjghdftpvidkbftqbpeahxbfyamonazvubzirhqseetaneptnpjbtrtitttxsyjckjvwtrmuwgidkofvobrwrffzrpnxbectsydbvswstfiqranjzhsebjnmprjoirqkgttahrivkcjtitdcpohwwerwgrdivqbltfnigavydxpmitttjjzyrmpaptkczzgnsovebvxezkkovgqegctxacvjfqwtiycnhartzczcgosiquhmdbljjzyrnmffcwnkyzytnsvyzayrieqyrfpxintbbiyrawxlguzaisedwabpzvevlejadztuclcpwvonehkhknicdksdcnjfaoeaqhcdkdtywilwewadcnaprcasccdcnvdgjdqirrsqwzhqqorlhbgpelpupdvuynzybcqkffnnpocidkkigimsa"; 
  char *result = longestPalindrome(input);

  printf("result : %s", result);

  return 0;
}
