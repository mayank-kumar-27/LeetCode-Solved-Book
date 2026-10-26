class Solution {
    int m, n;
    int[] d = {-1, 0, 1, 0, -1};
    public int countIslands(int[][] g, int k) {
        m = g.length;
        n = g[0].length;
        int a = 0;
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
        if (g[i][j] > 0 && dfs(g, i, j) % k == 0) a++;
        return a;
    }
    long dfs(int[][] g, int i, int j) {
        long s = g[i][j];
        g[i][j] = 0;
        for (int d = 0; d < 4; d++) {
            int x = i + this.d[d], y = j + this.d[d + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && g[x][y] > 0) s += dfs(g, x, y);
        } return s;
    }
}