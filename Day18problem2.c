#include <stdlib.h>
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    
    int* result = (int*)malloc(numsSize * sizeof(int));
    
    // Build prefix products directly into result
    result[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        result[i] = result[i - 1] * nums[i - 1];
    }
    
    // Multiply with suffix products on the fly
    int suffixProduct = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        result[i] *= suffixProduct;
        suffixProduct *= nums[i];
    }
    
    return result;
}
