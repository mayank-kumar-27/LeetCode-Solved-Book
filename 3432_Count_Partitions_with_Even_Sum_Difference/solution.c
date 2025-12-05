int countPartitions(int* nums, int numsSize) {
    int t_sum = 0, l_sum = 0, count = 0;
    for (int i = 0; i < numsSize; i++) t_sum += nums[i];
    for (int i = 0; i < numsSize - 1; i++) {
        l_sum += nums[i];
        int r_sum = t_sum - l_sum;
        if ((l_sum - r_sum) % 2 == 0) count++;
    }
    return count;
}