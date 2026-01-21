double findMaxAverage(int* nums, int numsSize, int k) {
    long sum = 0, max = 0;
    for (int i = 0; i < k; i++) sum += nums[i];
    max = sum;

    for (int i = k; i < numsSize; i++) { sum = sum - nums[i - k] + nums[i]; max = (sum > max) ? sum : max; }
    return (double)max / k;
}
