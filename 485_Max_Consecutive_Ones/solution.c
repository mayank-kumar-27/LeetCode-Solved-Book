int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int max = 0, count = 0;
    for (int i = 0; i < numsSize; i++) {
        count = nums[i] == 1 ? count + 1 : 0;
        if (count > max) max = count;
    }
    return max;
}