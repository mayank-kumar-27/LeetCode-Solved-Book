int longestOnes(int* nums, int numsSize, int k) {
    int j = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) k--;
        if (k < 0 && nums[j++] == 0) k++;
    }
    return numsSize - j;
}