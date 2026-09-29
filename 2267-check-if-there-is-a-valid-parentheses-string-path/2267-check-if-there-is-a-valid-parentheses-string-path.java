class Solution {
    public boolean hasValidPath(char[][] g) {
        int n = g.length;
        int m = g[0].length;
        int l = n + m - 1;

        if (l % 2 == 1)
            return false;

        if (g[0][0] != '(' || g[n - 1][m - 1] != ')')
            return false;

        boolean[][][] d = new boolean[n][m][l + 1];

        d[0][0][1] = true;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int c = g[i][j] == '(' ? 1 : -1;

                if (i > 0) {
                    for (int b = 0; b <= l; ++b) {
                        if (!d[i - 1][j][b])
                            continue;

                        int x = b + c;

                        if (x >= 0)
                            d[i][j][x] = true;
                    }
                }

                if (j > 0) {
                    for (int b = 0; b <= l; ++b) {
                        if (!d[i][j - 1][b])
                            continue;

                        int x = b + c;

                        if (x >= 0)
                            d[i][j][x] = true;
                    }
                }
            }
        }

        return d[n - 1][m - 1][0];
    }
}