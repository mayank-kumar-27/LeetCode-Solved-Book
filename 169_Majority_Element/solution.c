int majorityElement(int* nums, int numsSize) {
    int c = 0, count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (count == 0) c = nums[i];
        count += (nums[i] == c) ? 1 : -1;
    }
    return c;
}