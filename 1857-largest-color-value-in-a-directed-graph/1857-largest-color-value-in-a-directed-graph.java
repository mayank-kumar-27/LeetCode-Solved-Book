class Solution {
    public int largestPathValue(String s, int[][] e) {
        int n = s.length(), m = e.length, a = 0;
        int[] in = new int[n];
        int[][] g = new int[n][];
        int[] z = new int[n];
        for (int[] x : e) z[x[0]]++;
        for (int i = 0; i < n; i++) g[i] = new int[z[i]];
        java.util.Arrays.fill(z, 0);
        for (int[] x : e) {
            g[x[0]][z[x[0]]++] = x[1];
            in[x[1]]++;
        }
        int[][] d = new int[n][26];
        int[] q = new int[n];
        int l = 0, r = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        if (in[i] == 0) q[r++] = i;
        while (l < r) {
            int u = q[l++];
            cnt++;
            d[u][s.charAt(u) - 'a']++;
            for (int v : g[u]) {
                for (int c = 0; c < 26; c++)
                    d[v][c] = Math.max(d[v][c], d[u][c]);
                if (--in[v] == 0) q[r++] = v;
            }
            for (int c = 0; c < 26; c++)
                a = Math.max(a, d[u][c]);
        } return cnt == n ? a : -1;
    }
}