class Solution {
    public int[] countServers(int n, int[][] l, int x, int[] q) {
        Arrays.sort(l, (a, b) -> Integer.compare(a[1], b[1]));

        int m = q.length;
        Integer[] p = new Integer[m];
        for (int i = 0; i < m; i++) p[i] = i;
        Arrays.sort(p, (a, b) -> Integer.compare(q[a], q[b]));

        int[] a = new int[m];
        int[] c = new int[n + 1];
        int j = 0, k = 0, v = 0;

        for (int i : p) {
            int t = q[i];
            while (k < l.length && l[k][1] <= t) {
                int s = l[k++][0];
                if (c[s]++ == 0) {
                    ++v;
                }
            }
            while (j < k && l[j][1] < t - x) {
                int s = l[j++][0];
                if (--c[s] == 0) {
                    --v;
                }
            }
            a[i] = n - v;
        }
        return a;
    }
}