/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compareInts(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int* transformArray(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            result[i] = 0;
        } else {
            result[i] = 1;
        }
    }
    qsort(result, numsSize, sizeof(int), compareInts);
    *returnSize = numsSize;

    return result;
}