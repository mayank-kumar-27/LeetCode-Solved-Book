class Solution {
    boolean dfs(int[][] g, int r, int c) {
        if (r < 0 || c < 0 || r >= g.length || c >= g[0].length) return false;
        if (g[r][c] == 1) return true;
        g[r][c] = 1;
        boolean a = dfs(g, r - 1, c);
        boolean b = dfs(g, r + 1, c);
        boolean d = dfs(g, r, c - 1);
        boolean e = dfs(g, r, c + 1);
        return a && b && d && e;
    }
    public int closedIsland(int[][] g) {
        int n = g.length, m = g[0].length, c = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        if (g[i][j] == 0 && dfs(g, i, j)) c++;
        return c;
    }
}