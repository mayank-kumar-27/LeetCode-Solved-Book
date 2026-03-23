int maxProductPath(int** g, int m, int* cs) {
    int n = cs[0];
    long M = 1000000007;
    long **mn = malloc(m * sizeof(long*)), **mx = malloc(m * sizeof(long*));
    for (int i = 0; i < m; i++) {
        mn[i] = malloc(n * sizeof(long));
        mx[i] = malloc(n * sizeof(long));
        for (int j = 0; j < n; j++) mn[i][j] = LONG_MAX, mx[i][j] = LONG_MIN;
    }
    mn[0][0] = mx[0][0] = g[0][0];
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
        if (i || j) {
        long v = g[i][j], a[4], k = 0;
        if (i) a[k++] = mn[i-1][j]*v, a[k++] = mx[i-1][j]*v;
        if (j) a[k++] = mn[i][j-1]*v, a[k++] = mx[i][j-1]*v;
        long mi = LONG_MAX, ma = LONG_MIN;
        for (int t = 0; t < k; t++)
        if (a[t] < mi) mi = a[t], ma = ma > a[t] ? ma : a[t];
        else ma = ma > a[t] ? ma : a[t];
        mn[i][j] = mi, mx[i][j] = ma;
    }
    long r = mx[m-1][n-1];
    return r >= 0 ? r % M : -1;
}