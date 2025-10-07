int compareInts(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int findKthLargest(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compareInts);
    return nums[numsSize - k];
}