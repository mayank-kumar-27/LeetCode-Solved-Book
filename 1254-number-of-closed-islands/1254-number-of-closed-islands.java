class Solution {
    public int closedIsland(int[][] g) {
        int m = g.length, n = g[0].length, c = 0;
        boolean[][] v = new boolean[m][n];
        for (int i = 1; i < m - 1; i++) for (int j = 1; j < n - 1; j++)
        if (g[i][j] == 0 && !v[i][j] && bfs(i, j, g, v)) c++;
        return c;
    }
    boolean bfs(int x, int y, int[][] g, boolean[][] v) {
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{x, y});
        v[x][y] = true;
        boolean b = true;
        int[] d = {0, 1, 0, -1, 0};
        while (!q.isEmpty()) {
            int[] p = q.poll();
            int r = p[0], c = p[1];
            if (r == 0 || c == 0 || r == g.length - 1 || c == g[0].length - 1) b = false;
            for (int i = 0; i < 4; i++) {
                int a = r + d[i], z = c + d[i + 1];
                if (a >= 0 && a < g.length && z >= 0 && z < g[0].length && g[a][z] == 0 && !v[a][z]) {
                    v[a][z] = true;
                    q.offer(new int[]{a, z});
                }
            }
        } return b;
    }
}