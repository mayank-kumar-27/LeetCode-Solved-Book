int GCD(int a, int b) { return b == 0 ? a : GCD(b, a % b); }
bool isGoodArray(int* nums, int numsSize) {
    int gcd = nums[0];
    for (int i = 1; i < numsSize; i++) {
        gcd = GCD(gcd, nums[i]);
    }
    return gcd == 1;
}