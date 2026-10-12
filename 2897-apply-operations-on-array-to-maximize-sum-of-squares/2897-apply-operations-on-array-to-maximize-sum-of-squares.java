class Solution {
    public int maxSum(List<Integer> nums, int k) {
        final int MOD = 1000000007;
        int[] c = new int[30];
        for (int num : nums) for (int i = 0; i < 30; i++) {
            if ((num & (1 << i)) != 0) c[i]++;
        }
        long r = 0;
        for (int i = 0; i < k; i++) {
            long cr = 0;
            for (int j = 29; j >= 0; j--) {
                if (c[j] > 0) { cr |= 1L << j; c[j]--; }
            }
            r = (r + cr * cr) % MOD;
        } return (int) r;
    }
}