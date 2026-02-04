/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = 0;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            result[(*returnSize)++] = nums[i];
        }
    }

    return result;
}