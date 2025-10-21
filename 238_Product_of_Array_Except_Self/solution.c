/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int n = numsSize;
    *returnSize = n;

    int* res = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        res[i] = 1;
    }
    
    // Build prefix products directly into res
    int prefix = 1;
    for (int i = 0; i < n; i++) {
        res[i] = prefix;
        prefix *= nums[i];
    }
    
    // Multiply by suffix products
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        res[i] *= suffix;
        suffix *= nums[i];
    }
    
    return res;
}