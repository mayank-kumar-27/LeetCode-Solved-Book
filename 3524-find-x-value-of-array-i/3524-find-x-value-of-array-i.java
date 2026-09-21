class Solution {
    public long[] resultArray(int[] a, int k) {
        long[] ans = new long[k];
        long[] dp = new long[k];
        for (int x : a) {
            x %= k;
            long[] nd = new long[k];
            nd[x]++;
            for (int r = 0; r < k; r++)
                nd[(int)((long)r * x % k)] += dp[r];
            dp = nd;
            for (int r = 0; r < k; r++) ans[r] += dp[r];
        } return ans;
    }
}