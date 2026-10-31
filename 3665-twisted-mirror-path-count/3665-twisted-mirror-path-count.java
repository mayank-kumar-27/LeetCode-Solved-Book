class Solution {
    public int uniquePaths(int[][] g) {
        int m = g.length, n = g[0].length, M = 1000000007;
        int[][][] dp = new int[m][n][2];
        dp[0][0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) dp[i][j][0] = (g[i - 1][j] == 0 ? dp[i - 1][j][0] + dp[i - 1][j][1] : dp[i - 1][j][1]) % M;
                if (j > 0) dp[i][j][1] = (g[i][j - 1] == 0 ? dp[i][j - 1][0] + dp[i][j - 1][1] : dp[i][j - 1][0]) % M;
            }
        }
        return (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % M;
    }
}