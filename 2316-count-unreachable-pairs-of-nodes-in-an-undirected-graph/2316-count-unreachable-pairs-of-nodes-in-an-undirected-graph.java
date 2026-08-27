class Solution {
    int[] p, s;
    int f(int x) {
        return p[x] == x ? x : (p[x] = f(p[x]));
    }
    public long countPairs(int n, int[][] e) {
        p = new int[n];
        s = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = i;
            s[i] = 1;
        }
        for (int[] x : e) {
            int a = f(x[0]), b = f(x[1]);
            if (a != b) {
                p[a] = b;
                s[b] += s[a];
            }
        }
        long ans = 0, t = 0;
        for (int i = 0; i < n; i++) {
            if (p[i] == i) {
                ans += t * s[i];
                t += s[i];
            }
        } return ans;
    }
}