bool canReach(int* a, int n, int s) {
    int *q = malloc(n * sizeof(int)), f = 0, r = 0;
    bool* v = calloc(n, sizeof(bool));
    q[r++] = s;
    v[s] = 1;
    while (f < r) {
        int i = q[f++], x = i + a[i], y = i - a[i];
        if (!a[i]) return 1;
        if (x < n && !v[x]) v[x] = 1, q[r++] = x;
        if (y >= 0 && !v[y]) v[y] = 1, q[r++] = y;
    }
    free(q); free(v);
    return 0;
}
