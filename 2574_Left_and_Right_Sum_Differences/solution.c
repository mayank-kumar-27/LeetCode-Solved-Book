/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftRightDifference(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    int total = 0, left_sum = 0;
    for (int i = 0; i < numsSize; i++) total += nums[i];

    for (int i = 0; i < numsSize; i++) {
        int right_sum = total - left_sum - nums[i];
        result[i] = abs(left_sum - right_sum);
        left_sum += nums[i];
    }
    return result;
}