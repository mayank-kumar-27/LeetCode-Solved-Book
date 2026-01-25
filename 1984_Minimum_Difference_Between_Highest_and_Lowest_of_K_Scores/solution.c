#include <stdlib.h>

int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int minimumDifference(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);
    int result = nums[k - 1] - nums[0];
    for (int i = 0; i + k <= numsSize; i++) result = result > nums[i + k - 1] - nums[i] ? nums[i + k - 1] - nums[i] : result;
    return result;
}