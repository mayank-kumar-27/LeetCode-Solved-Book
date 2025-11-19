bool found(int* nums, int numsSize, int original) {
    for (int i = 0; i < numsSize; i++) if (nums[i] == original) return true;
    return false;
}
int findFinalValue(int* nums, int numsSize, int original) {
    while (found(nums, numsSize, original)) original *= 2;
    return original;
}