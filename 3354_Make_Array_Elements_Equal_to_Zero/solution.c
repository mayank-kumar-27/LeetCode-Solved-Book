int countValidSelections(int* nums, int numsSize) {
    int total = 0;
    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
    }

    int left_sum = 0, count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            int right_sum = total - left_sum;
            int diff = abs(left_sum - right_sum);
            count += (diff == 0) ? 2 : (diff == 1) ? 1 : 0;
        }
        left_sum += nums[i];
    }

    return count;
}