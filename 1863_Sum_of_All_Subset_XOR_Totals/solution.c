int subsetXORSum(int* nums, int numsSize) {
    int or_result = 0;
    for (int i = 0; i < numsSize; i++) or_result |= nums[i];
    return or_result << (numsSize - 1);
}