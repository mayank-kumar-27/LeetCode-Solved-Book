int comp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int partitionArray(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(nums[0]), comp);
    int min = nums[0], count = 1;
    for (int i = 0; i < numsSize; i++) if (nums[i] - min > k) { count++, min = nums[i]; }
    return count;
}