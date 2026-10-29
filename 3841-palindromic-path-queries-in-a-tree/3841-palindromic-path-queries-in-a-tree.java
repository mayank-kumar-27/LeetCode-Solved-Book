class BIT {
    int[] t;
    int n;

    BIT(int n) {
        this.n = n;
        t = new int[n + 1];
    }

    int lb(int x) {
        return x & -x;
    }

    void update(int x, int v) {
        while (x <= n) {
            t[x] ^= v;
            x += lb(x);
        }
    }

    int query(int x) {
        int r = 0;
        while (x > 0) {
            r ^= t[x];
            x -= lb(x);
        }
        return r;
    }

    void updateRange(int l, int r, int v) {
        update(l, v);
        update(r + 1, v);
    }
}

class Solution {
    List<List<Integer>> g;
    int[][] f;
    int[] d, l, r;
    int tm, log;

    public List<Boolean> palindromePath(int n, int[][] edges, String s, String[] queries) {
        g = new ArrayList<>();
        for (int i = 0; i < n; i++) g.add(new ArrayList<>());

        for (int[] e : edges) {
            g.get(e[0]).add(e[1]);
            g.get(e[1]).add(e[0]);
        }

        log = 32 - Integer.numberOfLeadingZeros(n);
        f = new int[n][log];
        d = new int[n];
        l = new int[n];
        r = new int[n];
        tm = 0;

        dfs(0, 0);

        for (int j = 1; j < log; j++)
            for (int i = 0; i < n; i++)
                f[i][j] = f[f[i][j - 1]][j - 1];

        BIT b = new BIT(n + 1);
        char[] c = s.toCharArray();

        for (int i = 0; i < n; i++)
            b.updateRange(l[i], r[i], 1 << (c[i] - 'a'));

        List<Boolean> ans = new ArrayList<>();

        for (String q : queries) {
            String[] p = q.split(" ");

            if (p[0].equals("update")) {
                int u = Integer.parseInt(p[1]);
                char x = p[2].charAt(0);

                b.updateRange(l[u], r[u],
                    (1 << (c[u] - 'a')) ^ (1 << (x - 'a')));

                c[u] = x;
            } else {
                int u = Integer.parseInt(p[1]);
                int v = Integer.parseInt(p[2]);
                int w = lca(u, v);

                int m = b.query(l[u]) ^ b.query(l[v])
                      ^ (1 << (c[w] - 'a'));

                ans.add(Integer.bitCount(m) <= 1);
            }
        }

        return ans;
    }

    void dfs(int u, int p) {
        l[u] = ++tm;
        f[u][0] = p;

        for (int v : g.get(u)) {
            if (v == p) continue;
            d[v] = d[u] + 1;
            dfs(v, u);
        }

        r[u] = tm;
    }

    int lca(int u, int v) {
        if (d[u] < d[v]) {
            int t = u;
            u = v;
            v = t;
        }

        int x = d[u] - d[v];

        for (int i = 0; i < log; i++)
            if (((x >> i) & 1) == 1)
                u = f[u][i];

        if (u == v) return u;

        for (int i = log - 1; i >= 0; i--) {
            if (f[u][i] != f[v][i]) {
                u = f[u][i];
                v = f[v][i];
            }
        }

        return f[u][0];
    }
}