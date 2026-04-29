long long maximumScore(int** g, int gs, int* gc) {
    int n = gc[0];
    if (n == 1) return 0;
    long long*** d = (long long***)malloc(n * sizeof(long long**));
    for (int i = 0; i < n; i++) {
        d[i] = (long long**)malloc((n + 1) * sizeof(long long*));
        for (int j = 0; j <= n; j++) d[i][j] = (long long*)calloc(n + 1, sizeof(long long));
    }
    long long** p = (long long**)malloc((n + 1) * sizeof(long long*));
    for (int i = 0; i <= n; i++) p[i] = (long long*)calloc(n + 1, sizeof(long long));
    long long** s = (long long**)malloc((n + 1) * sizeof(long long*));
    for (int i = 0; i <= n; i++) s[i] = (long long*)calloc(n + 1, sizeof(long long));
    long long** c = (long long**)malloc(n * sizeof(long long*));
    for (int i = 0; i < n; i++) {
        c[i] = (long long*)calloc(n + 1, sizeof(long long));
        for (int j = 1; j <= n; j++) c[i][j] = c[i][j - 1] + g[j - 1][i];
    }
    for (int i = 1; i < n; i++) {
        for (int x = 0; x <= n; x++) {
            for (int y = 0; y <= n; y++) {
                if (x <= y) { long long e = c[i][y] - c[i][x]; d[i][x][y] = fmax(d[i][x][y], s[y][0] + e); } 
                else { long long e = c[i - 1][x] - c[i - 1][y]; d[i][x][y] = fmax(d[i][x][y], fmax(s[y][x], p[y][x] + e)); }
            }
        }
        for (int x = 0; x <= n; x++) {
            p[x][0] = d[i][x][0];
            for (int y = 1; y <= n; y++) {
                long long q = (y > x) ? (c[i][y] - c[i][x]) : 0;
                p[x][y] = fmax(p[x][y - 1], d[i][x][y] - q);
            }
            s[x][n] = d[i][x][n];
            for (int y = n - 1; y >= 0; y--) s[x][y] = fmax(s[x][y + 1], d[i][x][y]);
        }
    }
    long long a = 0;
    for (int k = 0; k <= n; k++) a = fmax(a, fmax(d[n - 1][n][k], d[n - 1][0][k]));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) free(d[i][j]);
        free(d[i]);
    }
    free(d);
    for (int i = 0; i <= n; i++) {free(p[i]); free(s[i]);}
    free(p);
    free(s);
    for (int i = 0; i < n; i++) free(c[i]);
    free(c);
    return a;
}
