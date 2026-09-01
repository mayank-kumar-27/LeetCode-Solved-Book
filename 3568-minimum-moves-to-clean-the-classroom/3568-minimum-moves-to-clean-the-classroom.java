class Solution {
    static int[] dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

    public int minMoves(String[] a, int e) {
        int m = a.length, n = a[0].length(), k = 0, sx = 0, sy = 0;
        int[][] id = new int[m][n];

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                char c = a[i].charAt(j);
                if (c == 'S') { sx = i; sy = j; }
                else if (c == 'L') id[i][j] = 1 << k++;
            }

        int f = 1 << k;
        int[][][] v = new int[m][n][f];

        for (int[][] x : v)
            for (int[] y : x)
                java.util.Arrays.fill(y, -1);

        java.util.ArrayDeque<int[]> q = new java.util.ArrayDeque<>();
        q.add(new int[]{sx, sy, 0, e, 0});
        v[sx][sy][0] = e;

        while (!q.isEmpty()) {
            int[] x = q.poll();
            int r = x[0], c = x[1], mask = x[2], en = x[3], d = x[4];

            if (mask == f - 1) return d;
            if (en == 0) continue;

            for (int z = 0; z < 4; z++) {
                int nr = r + dx[z], nc = c + dy[z];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n ||
                    a[nr].charAt(nc) == 'X') continue;

                int ne = a[nr].charAt(nc) == 'R' ? e : en - 1;
                int nm = mask | id[nr][nc];

                if (ne > v[nr][nc][nm]) {
                    v[nr][nc][nm] = ne;
                    q.add(new int[]{nr, nc, nm, ne, d + 1});
                }
            }
        }

        return -1;
    }
}