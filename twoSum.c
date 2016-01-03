#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *newArr = (int *)malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        newArr[i] = nums[i];
    }
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < (numsSize - i - 1); j++) {
            if (newArr[j] > newArr[j+1]) {
                int temp = newArr[j];
                newArr[j] = newArr[j+1];
                newArr[j+1] = temp;
            }
        }
    }
    
    int low = 0, high = numsSize - 1;
    while (low < high) {
        int sum = newArr[low] + newArr[high];
        if (sum == target) {
            break;
        } else if (sum < target) {
            low += 1;
        } else {
            high -= 1;
        }
    }
    
    if (low < high) {
        printf("%d %d\n", newArr[low], newArr[high]);
        int index1 = -1;
        int index2 = -1;
        
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] == newArr[low] && index1 == -1) {
                index1 = i + 1;
            } else if (nums[i] == newArr[high]) {
                index2 = i + 1;
            }
            if (index1 != -1 && index2 != -1) {
                break;
            }
        }
        
        int *result = (int *)malloc(2 * sizeof(int));
        result[0] = index1 < index2 ? index1 : index2;
        result[1] = index1 < index2 ? index2 : index1;
        
        return result;
    } else {
        return NULL;
    }
}

int main(int argc, char *argv[]) {
  int arr[] = {0, 4, 3, 0};
  int *result = twoSum(arr, 4, 0);
  printf("%d %d\n", result[0], result[1]);
  return 0;
}
