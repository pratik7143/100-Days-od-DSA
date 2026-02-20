#include <stdio.h>
#include <stdlib.h>
void quicksort(int* a, int l, int r) {
    while (l < r) {
        int i = l, j = r;
        int pivot = a[(l + r) >> 1];
        while (i <= j) {
            while (a[i] < pivot) i++;
            while (a[j] > pivot) j--;
            if (i <= j) {
                int tmp = a[i]; 
                a[i] = a[j]; 
                a[j] = tmp;
                i++; 
                j--;
            }
        }
        if (j - l < r - i) {
            if (l < j) quicksort(a, l, j);
            l = i;
        } else {
            if (i < r) quicksort(a, i, r);
            r = j;
        }
    }
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;

    if (numsSize < 3) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    // SORT
    quicksort(nums, 0, numsSize - 1);

    // Preallocate for worst-case scenario
    int capacity = 20000;
    int** res = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        // skip duplicate nums[i]
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int target = -nums[i];
        int l = i + 1;
        int r = numsSize - 1;

        while (l < r) {
            int sum = nums[l] + nums[r];

            if (sum < target) {
                l++;
            } else if (sum > target) {
                r--;
            } else {
                // FOUND TRIPLET
                res[*returnSize] = (int*)malloc(3 * sizeof(int));
                res[*returnSize][0] = nums[i];
                res[*returnSize][1] = nums[l];
                res[*returnSize][2] = nums[r];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                // Avoid overflow by doubling capacity
                if ((*returnSize) == capacity) {
                    capacity <<= 1;
                    res = (int**)realloc(res, capacity * sizeof(int*));
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
                }

                // Skip duplicates
                int leftVal = nums[l];
                int rightVal = nums[r];

                while (l < r && nums[l] == leftVal) l++;
                while (l < r && nums[r] == rightVal) r--;
            }
        }
    }

    return res;
}
