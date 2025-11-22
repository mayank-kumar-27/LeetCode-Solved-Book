/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int* present = (int*)calloc(numsSize + 1, sizeof(int));
    int* result = (int*)malloc(numsSize * sizeof(int));
    int index = 0;

    for (int i = 0; i < numsSize; i++) {
        present[nums[i]] = 1;
    }

    for (int i = 1; i <= numsSize; i++) {
        if (present[i] == 0) {
            result[index++] = i;
        }
    }

    *returnSize = index;
    free(present);
    return result;
}
