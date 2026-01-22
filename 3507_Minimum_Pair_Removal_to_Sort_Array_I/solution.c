bool is_sorted(int* arr, int n) {
    for (int i = 1; i < n; i++) if (arr[i] < arr[i - 1]) return false;
    return true;
}
int minimumPairRemoval(int* nums, int numsSize) {
    int ops = 0;
    while (!is_sorted(nums, numsSize)) { 
        ops++;
        int min_sum = INT_MAX, index = -1;
        for (int i = 1; i < numsSize; i++) {
            int current_sum = nums[i - 1] + nums[i];
            if (current_sum < min_sum) { min_sum = current_sum; index = i; }
        }
        nums[index - 1] = min_sum;
        for (int i = index; i < numsSize - 1; i++) nums[i] = nums[i + 1];
        numsSize -= 1;
    }
    return ops;
}
