// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
// int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
//     int i = 0, j = 0;
//     int* result = (int*)malloc(numsSize * sizeof(int));

//     while (i < numsSize) {
//         result[i] = nums[j];
//         result[i + 1] = nums[n];
//         i += 2;
//         j++;
//         n++;
//     }

//     *returnSize = numsSize;
//     return result;
// }

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));

    for (int i = 0; i < n; i++) {
        result[2 * i] = nums[i];
        result[2 * i + 1] = nums[n + i];
    }

    *returnSize = numsSize;
    return result;
}