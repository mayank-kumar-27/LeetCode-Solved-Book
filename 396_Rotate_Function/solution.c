int max(int a, int b) { return a > b ? a : b; }
int maxRotateFunction(int* nums, int numsSize) {
    int n = 0, s = 0;
    for (int i = 0; i < numsSize; i++) { n += i * nums[i]; s += nums[i]; }
    int r = n;
    for (int i = numsSize - 1; i > 0; i--) { n += s - numsSize * nums[i]; r = max(r, n); }
    return r;
}