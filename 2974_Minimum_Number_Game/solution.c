/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int comp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int* numberGame(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    qsort(nums, numsSize, sizeof(int), comp);

    for (int i = 0; i < numsSize; i += 2) {
        result[i] = nums[i + 1];
        result[i + 1] = nums[i];
    }

    *returnSize = numsSize;
    return result;
}