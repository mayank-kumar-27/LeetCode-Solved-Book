import java.util.*;
class Solution {
    public int shortestPath(int n, int[][] e, String s, int k) {
        List<int[]>[] g = new ArrayList[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (int[] p : e) g[p[0]].add(new int[]{p[1], p[2]});
        int[][] d = new int[n][k + 1];
        for (int[] r : d) Arrays.fill(r, 1 << 30);
        PriorityQueue<int[]> q = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        q.offer(new int[]{d[0][1] = 0, 0, 1});
        while (!q.isEmpty()) {
            int[] t = q.poll();
            int w = t[0], u = t[1], c = t[2];
            if (w > d[u][c]) continue;
            if (u == n - 1) return w;
            for (int[] a : g[u]) {
                int v = a[0], l = s.charAt(u) == s.charAt(v) ? c + 1 : 1;
                if (l <= k && w + a[1] < d[v][l]) {
                    d[v][l] = w + a[1];
                    q.offer(new int[]{d[v][l], v, l});
                }
            }
        } return -1;
    }
}