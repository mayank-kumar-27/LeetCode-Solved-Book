class Solution {
    public int countServers(int[][] g) {
        if (g == null || g.length == 0) return 0;
        int r = g.length, c = g[0].length;
        int[] rc = new int[c], cc = new int[r];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (g[i][j] == 1) {
                    rc[j]++;
                    cc[i]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (g[i][j] == 1 && (rc[j] > 1 || cc[i] > 1)) {
                    ans++;
                }
            }
        }
        return ans;
    }
}