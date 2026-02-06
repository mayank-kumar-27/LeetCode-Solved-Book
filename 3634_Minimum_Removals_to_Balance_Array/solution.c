int comp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int minRemoval(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), comp);
    int max_len = 1, low = 0;
    for (int high = 0; high < numsSize; high++) {
        while (low < high && nums[high] > (long long)nums[low] * k) low++;
        if (high - low + 1 > max_len) max_len = high - low + 1;
    }
    return numsSize - max_len;
}