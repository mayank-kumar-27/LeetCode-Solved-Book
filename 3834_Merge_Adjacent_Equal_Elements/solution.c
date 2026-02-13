/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* mergeAdjacent(int* nums, int numsSize, int* returnSize) {
    long long* stack = (long long*)malloc(numsSize * sizeof(long long));
    int top = 0;
    for (int i = 0; i < numsSize; i++) {
        long long v = nums[i];
        while (top > 0 && stack[top - 1] == v) {
            v += stack[top - 1];
            top--;
        }
        stack[top++] = v;
    }
    *returnSize = top;
    return stack;
}