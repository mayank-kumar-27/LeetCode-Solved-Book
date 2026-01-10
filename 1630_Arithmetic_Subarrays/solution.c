/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int comp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize, int* r, int rSize, int* returnSize) {
    *returnSize = lSize;
    bool* result = (bool*)malloc(lSize * sizeof(bool));

    for (int i = 0; i < lSize; i++) {
        int size = r[i] - l[i] + 1;
        if (size < 2) { result[i] = true; continue; }

        int* subarray = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) subarray[j] = nums[l[i] + j];
        qsort(subarray, size, sizeof(int), comp);

        bool isArithmetic = true;
        int diff = subarray[1] - subarray[0];
        for (int k = 2; k < size; k++) if (subarray[k] - subarray[k - 1] != diff) { isArithmetic = false; break; }
        result[i] = isArithmetic;
        free(subarray);
    }
    return result;
}
