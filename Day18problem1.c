#include <stdio.h>
void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    if (numsSize == 0) return;

    k = k % numsSize;  // Handle k > numsSize

    // Step 1: Reverse entire array
    reverse(nums, 0, numsSize - 1);

    // Step 2: Reverse first k elements
    reverse(nums, 0, k - 1);

    // Step 3: Reverse remaining elements
    reverse(nums, k, numsSize - 1);
}

// For testing
int main() {
    int nums[] = {1,2,3,4,5,6,7};
    int k = 3;
    int size = sizeof(nums)/sizeof(nums[0]);

    rotate(nums, size, k);

    printf("Rotated Array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}

