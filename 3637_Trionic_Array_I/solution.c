bool isTrionic(int* nums, int numsSize) {
    int i = 0;
    while (i < numsSize - 1 && nums[i] < nums[i + 1]) i++;
    if (i == 0 || i == numsSize - 1) return false;
    while (i < numsSize - 1 && nums[i] > nums[i + 1]) i++;
    if (i == numsSize - 1) return false;
    while (i < numsSize - 1 && nums[i] < nums[i + 1]) i++;
    return (i == numsSize - 1);
}