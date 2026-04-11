int minimumDistance(int* a, int n) {
    int m = 0;
    for (int i = 0; i < n; i++) if (a[i] > m) m = a[i];
    int p[m + 1][2];
    for (int i = 0; i <= m; i++) p[i][0] = p[i][1] = -1;
    int r = 1 << 30;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        if (p[x][1] != -1) {
            int d = (i - p[x][1]) << 1;
            if (d < r) r = d;
        }
        int t = p[x][0];
        p[x][0] = i;
        p[x][1] = t;
    }
    return (r == (1 << 30)) ? -1 : r;
}
