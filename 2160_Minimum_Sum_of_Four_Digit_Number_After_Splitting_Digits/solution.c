int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int minimumSum(int num) {
    int nums[4];
    for (int i = 0; i < 4; i++) nums[i] = num % 10, num /= 10;
    qsort(nums, 4, sizeof(int), compare);
    return (nums[0] * 10 + nums[3]) + (nums[1] * 10 + nums[2]);
}