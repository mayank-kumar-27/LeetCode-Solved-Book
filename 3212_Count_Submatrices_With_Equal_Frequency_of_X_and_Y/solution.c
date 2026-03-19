int numberOfSubmatrices(char** g, int r, int* cs) {
    int c = cs[0];
    int x[c], y[c], ans = 0;
    for (int j = 0; j < c; j++) x[j] = y[j] = 0;
    for (int i = 0; i < r; i++) {
        int a = 0, b = 0;
        for (int j = 0; j < c; j++) {
            a += (g[i][j] == 'X');
            b += (g[i][j] == 'Y');
            x[j] += a;
            y[j] += b;
            if (x[j] > 0 && x[j] == y[j]) ans++;
        }
    }
    return ans;
}