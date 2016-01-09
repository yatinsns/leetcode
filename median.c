#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

double find_median_of_numbers(int *arr, int size) {
    for (int i = 0; i < (size - 1); i++) {
      for (int j = 0; j < (size - 1 - i); j++) {
        if (arr[j + 1] < arr[j]) {
          int temp = arr[j + 1];
          arr[j + 1] = arr[j];
          arr[j] = temp;
        }
      }
    }
    int lower = 0, higher = size - 1;
    if (size % 2 == 0) {
      int mid = (higher - lower + 1) / 2;
      return (arr[mid] + arr[mid - 1]) / 2.0;
    } else {
      return arr[(higher - lower) / 2];
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        // Need to swap such that num1Size should be smaller than num2Size
        int *tmp = nums1;
        nums1 = nums2;
        nums2 = tmp;
        
        int tempSize = nums1Size;
        nums1Size = nums2Size;
        nums2Size = tempSize;
    }

    if (nums1Size == 0) {
        return find_median_of_numbers(nums2, nums2Size);
    }
    
    // Now num1Size is smaller than num2Size
    int lower1 = 0, higher1 = nums1Size - 1;
    int lower2 = 0, higher2 = nums2Size - 1;
    
    while (higher1 - lower1 > 1) {
      int currentNums1Size = higher1 - lower1 + 1;
      int currentNums2Size = higher2 - lower2 + 1;

      int mid1 = lower1 + ceil((higher1 - lower1) / 2.0); 
      int mid2 = lower2 + ceil((higher2 - lower2) / 2.0);

      if (nums1[mid1] < nums2[mid2]) {
        int min;
        if (currentNums1Size % 2 == 0) {
          min = MIN(mid1 - lower1 -1, higher2 - mid2);
        } else {
          min = MIN(mid1 - lower1, higher2 - mid2);
        }
        lower1 += min;
        higher2 -= min;
      } else {
        int min;
        if (currentNums2Size % 2 == 0) {
          min = MIN(higher1 - mid1, mid2 - lower2 - 1);
        } else {
          min = MIN(higher1 - mid1, mid2 - lower2);
        }
        lower2 += min;
        higher1 -= min;
      } 
    }
    
    double median;
    int currentNums2Size = higher2 - lower2 + 1;

    int *res;
    int arrSize;

    //for (int i = lower1; i <= higher1; i++) {
    //  printf("%d ", nums1[i]);
    //}

   //printf("\n\n");

   //for (int i = lower2; i <= higher2; i++) {
   //   printf("%d ", nums2[i]);
   // }



    if (lower1 == higher1) {
      if (currentNums2Size == 1) {
        int arr[] = {nums1[lower1], nums2[lower2]};
        arrSize = 2;
        res = arr;
      } else if (currentNums2Size % 2 == 0) {
        int mid2 = lower2 + (higher2 - lower2 + 1) / 2;
        if (nums1[lower1] < nums2[mid2 - 1]) {
          int arr[] = {nums2[mid2 - 1]};
          arrSize = 1;
          res = arr;
        } else if (nums2[mid2] < nums1[lower1]) {
          int arr[] = {nums2[mid2]};
          arrSize = 1;
          res = arr;
        } else {
          int arr[] = {nums1[lower1]};
          arrSize = 1;
          res = arr;
        }
      } else {
        int mid2 = lower2 + (higher2 - lower2) / 2;
        if (nums1[lower1] < nums2[mid2]) {
          int arr[] = {MAX(nums1[lower1], nums2[mid2 - 1]),nums2[mid2]};
          arrSize = 2;
          res = arr;
        } else {
          int arr[] = {nums2[mid2], MIN(nums1[lower1], nums2[mid2 + 1])};
          arrSize = 2;
          res = arr;
        }
      }
    } else {
      if (currentNums2Size == 2) {
        int arr[] = {nums1[lower1], nums1[higher1],
               nums2[lower2], nums2[higher2]};
        arrSize = 4;
        res = arr; 
      } else if (currentNums2Size % 2 == 0) {
        int mid2 = lower2 + (higher2 - lower2 + 1) / 2;
        int arr[] =  {nums2[mid2], nums2[mid2 - 1], MAX(nums1[lower1], nums2[mid2 - 2]), MIN(nums1[higher1], nums2[mid2 + 1])};
        arrSize = 4;
        res = arr;
      } else {
        int mid2 = lower2 + (higher2 - lower2) / 2;
        int arr[] = {nums2[mid2],MAX(nums1[lower1], nums2[mid2 - 1]),MIN(nums1[higher1], nums2[mid2 + 1])};
        arrSize = 3;
        res = arr;
      }
    }

    return find_median_of_numbers(res, arrSize);
}

int main(int argc, char *argv[]) {
    int arr1[] = {1, 4, 5, 6};
    int arr2[] = {2, 3, 7, 8};
    printf("\n--result--- %f", findMedianSortedArrays(arr1, 4, arr2, 4));
    return 0;
}
