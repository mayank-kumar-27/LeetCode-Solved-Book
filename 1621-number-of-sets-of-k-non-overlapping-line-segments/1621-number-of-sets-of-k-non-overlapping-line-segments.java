class Solution {
    private static final int MOD = 1000000007;
    public int numberOfSets(int n, int k) {
        int[] dp = new int[n];
        int[] pre = new int[n + 1];
        for (int j = 0; j < n; j++) {
            dp[j] = 1;
            pre[j + 1] = (pre[j] + dp[j]) % MOD;
        }
        for (int i = 1; i <= k; i++) {
            dp[0] = 0;
            for (int j = 1; j < n; j++) dp[j] = (dp[j - 1] + pre[j]) % MOD;
            for (int j = 0; j < n; j++) pre[j + 1] = (pre[j] + dp[j]) % MOD;
        } return dp[n - 1];
    }
}