int getMinDistance(int* nums, int numsSize, int target, int start) {
    int m = INT_MAX;
    for (int i = 0; i < numsSize; i++) if (nums[i] == target) m = m > abs(i - start) ? abs(i - start) : m;
    return m;
}
