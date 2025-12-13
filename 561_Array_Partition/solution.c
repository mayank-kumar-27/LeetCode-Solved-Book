int comp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int arrayPairSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), comp);
    int sum = 0;
    for (int i = 0; i < numsSize; i += 2) sum += nums[i];
    return sum;
}