int cmp(const void* a, const void* b) { return (*(int*)a) - (*(int*)b); }
int minimumCost(int* nums, int numsSize) {
    qsort(nums + 1, numsSize - 1, sizeof(int), cmp);
    return nums[0] + nums[1] + nums[2];
}