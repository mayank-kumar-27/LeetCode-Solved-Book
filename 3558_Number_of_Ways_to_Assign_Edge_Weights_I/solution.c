#define MOD 1000000007
typedef struct N {
    int v;
    struct N* n;
} N;
typedef struct {
    N** h;
} G;
void ae(G* g, int u, int v) {
    N* p = malloc(sizeof(N));
    p->v = v;
    p->n = g->h[u];
    g->h[u] = p;
}
int qp(int x, int y) {
    long long r = 1, b = x;
    while (y) {
        if (y & 1)
            r = r * b % MOD;
        b = b * b % MOD;
        y >>= 1;
    }
    return r;
}
int dfs(G* g, int x, int f) {
    int m = 0;
    for (N* p = g->h[x]; p; p = p->n) {
        int y = p->v;
        if (y != f) {
            int d = dfs(g, y, x) + 1;
            if (d > m)
                m = d;
        }
    }
    return m;
}
int assignEdgeWeights(int** e, int m, int* c) {
    int n = m + 1;
    G g;
    g.h = calloc(n + 1, sizeof(N*));
    for (int i = 0; i < m; i++) {
        int u = e[i][0], v = e[i][1];
        ae(&g, u, v);
        ae(&g, v, u);
    }
    int d = dfs(&g, 1, 0);
    int r = qp(2, d - 1);
    for (int i = 0; i <= n; i++) {
        N* p = g.h[i];
        while (p) {
            N* t = p;
            p = p->n;
            free(t);
        }
    }
    free(g.h);
    return r;
}