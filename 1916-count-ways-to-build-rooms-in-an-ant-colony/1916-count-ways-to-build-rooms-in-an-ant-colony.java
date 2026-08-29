class Solution {
    static final long M = 1000000007;

    public int waysToBuildRooms(int[] p) {
        int n = p.length;
        int[] h = new int[n];
        java.util.Arrays.fill(h, -1);

        int[] to = new int[n - 1];
        int[] nx = new int[n - 1];
        int e = 0;

        for (int i = 1; i < n; i++) {
            to[e] = i;
            nx[e] = h[p[i]];
            h[p[i]] = e++;
        }

        int[] o = new int[n], st = new int[n];
        int z = 0, t = 0;
        st[t++] = 0;

        while (t > 0) {
            int u = st[--t];
            o[z++] = u;

            for (int i = h[u]; i != -1; i = nx[i])
                st[t++] = to[i];
        }

        long[] f = new long[n + 1];
        long[] g = new long[n + 1];
        f[0] = 1;

        for (int i = 1; i <= n; i++)
            f[i] = f[i - 1] * i % M;

        g[n] = pw(f[n], M - 2);
        for (int i = n; i > 0; i--)
            g[i - 1] = g[i] * i % M;

        int[] s = new int[n];
        long r = 1;

        for (int j = n - 1; j >= 0; j--) {
            int u = o[j];
            s[u] = 1;

            for (int i = h[u]; i != -1; i = nx[i]) {
                int v = to[i];
                s[u] += s[v];
                r = r * g[s[v]] % M;
            }

            r = r * f[s[u] - 1] % M;
        }

        return (int) r;
    }

    static long pw(long a, long b) {
        long r = 1;
        while (b > 0) {
            if ((b & 1) != 0)
                r = r * a % M;
            a = a * a % M;
            b >>= 1;
        }
        return r;
    }
}