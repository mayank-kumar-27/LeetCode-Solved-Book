/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 0;

    int seen[100] = {0};

    for (int i = 0; i < numsSize; i++) {
        if (seen[nums[i]]) {
            result[*returnSize] = nums[i];
            (*returnSize)++;
        } else {
            seen[nums[i]] = 1;
        }
    }

    return result;
}