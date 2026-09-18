class Solution {
    public int minPathSum(int[][] g) {
        int m = g.length, n = g[0].length;
        int[] d = new int[n];
        d[0] = g[0][0];
        for (int j = 1; j < n; j++) d[j] = d[j - 1] + g[0][j];
        for (int i = 1; i < m; i++) {
            d[0] += g[i][0];
            for (int j = 1; j < n; j++) d[j] = Math.min(d[j], d[j - 1]) + g[i][j];
        } return d[n - 1];
    }
}