class Solution {
    public int maxLength(int[] nums) {
        int res = 2, p = 1, n = nums.length, l = 0, r = 0;
        while (r < n) {
            while (gcd(p, nums[r]) > 1) p /= nums[l++];
            p *= nums[r];
            res = Math.max(res, r - l + 1);
            r++;
        }  return res;
    }
    private int gcd(int a, int b) {
        while (b != 0) {
            int t = a;
            a = b; b = t % b;
        } return a;
    }
}