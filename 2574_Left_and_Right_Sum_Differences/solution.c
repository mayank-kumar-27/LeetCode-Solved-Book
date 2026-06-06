/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftRightDifference(int* nums, int n, int* rs) {
    int* r = (int*)malloc(n * sizeof(int));
    *rs = n;
    int t = 0, l = 0;
    for (int i = 0; i < n; i++) t += nums[i];
    for (int i = 0; i < n; i++) {
        int rt = t - l - nums[i];
        r[i] = abs(rt - l);
        l += nums[i];
    }
    return r;
}