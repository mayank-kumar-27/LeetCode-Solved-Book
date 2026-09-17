class Solution {
    public int minSumOfLengths(int[] a, int t) {
        int n = a.length, s = 0, l = 0, r = n + 1;
        int[] dp = new int[n + 1];
        for (int i = 0; i < n; i++) {
            dp[i + 1] = dp[i];
            s += a[i];
            while (s > t) s -= a[l++];
            if (s == t) {
                int len = i - l + 1;
                if (dp[l] > 0) r = Math.min(r, len + dp[l]);
                dp[i + 1] = Math.min(dp[i + 1] == 0 ? n + 1 : dp[i + 1], len);
            }
        } return r == n + 1 ? -1 : r;
    }
}