int comp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int minPairSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(nums[0]), comp);
    int max = 0, sum = 0;
    for (int i = 0; i < numsSize / 2; i++)
    { sum = nums[i] + nums[numsSize - 1 - i]; max = sum > max ? sum : max; }
    return max;
}
