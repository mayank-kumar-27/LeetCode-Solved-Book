class Solution {
    public int minimumChanges(String s, int k) {
        int n = s.length();
        int[][] c = new int[n][n];
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i + l <= n; i++) {
                int j = i + l - 1;
                c[i][j] = Integer.MAX_VALUE;
                for (int d = 1; d < l; d++) {
                    if (l % d != 0) continue;
                    int v = 0;
                    for (int a = 0; a < d; a++) {
                        int x = i + a;
                        int y = i + l - d + a;
                        while (x < y) {
                            if (s.charAt(x) != s.charAt(y)) v++;
                            x += d;
                            y -= d;
                        }
                    } c[i][j] = Math.min(c[i][j], v);
                }
            }
        }
        int[][] dp = new int[n + 1][k + 1];
        for (int[] a : dp) Arrays.fill(a, 1000000);
        dp[0][0] = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                for (int p = 2; p <= i; p++) {
                    dp[i][j] = Math.min(dp[i][j], dp[i - p][j - 1] + c[i - p][i - 1]);
                }
            }
        } return dp[n][k];
    }
}
