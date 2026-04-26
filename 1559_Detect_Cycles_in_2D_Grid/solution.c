int f(int* p, int x) {
    return p[x] == x ? x : (p[x] = f(p, p[x]));
}
bool containsCycle(char** g, int m, int* cs) {
    int n = cs[0];
    int* p = (int*)malloc(sizeof(int) * m * n);
    for (int i = 0; i < m * n; i++) p[i] = i;
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            int id = r * n + c;
            if (r > 0 && g[r][c] == g[r - 1][c]) {
                if (f(p, id) == f(p, id - n)) return true;
                p[f(p, id)] = f(p, id - n);
            }
            if (c > 0 && g[r][c] == g[r][c - 1]) {
                if (f(p, id) == f(p, id - 1)) return true;
                p[f(p, id)] = f(p, id - 1);
            }
        }
    }
    return false;
}
