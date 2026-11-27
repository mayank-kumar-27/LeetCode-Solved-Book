class Solution {
    public int maximumSaleItems(int[][] items, int budget) {
        int M = 1500, m = Integer.MAX_VALUE;
        int[] c = new int[M + 1], g = new int[M + 1];
        for (int[] t : items) { c[t[0]]++; m = Math.min(m, t[1]); }
        for (int f = 1; f <= M; f++) if (c[f] > 0) for (int k = f; k <= M; k += f) g[f] += c[k];
        int[] d = new int[budget + 1];
        for (int b = 0; b <= budget; b++) d[b] = b / m;
        for (int[] t : items) {
            int p = t[1], v = g[t[0]];
            for (int b = budget; b >= p; b--) d[b] = Math.max(d[b], d[b - p] + v);
        } return d[budget];
    }
}