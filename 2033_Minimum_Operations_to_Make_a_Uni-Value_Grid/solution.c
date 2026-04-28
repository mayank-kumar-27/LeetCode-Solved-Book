int c(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int minOperations(int** g, int r, int* cs, int x) {
    int t = 0, i, j, k = 0, a = 0;
    for (i = 0; i < r; i++) t += cs[i];
    int* v = malloc(sizeof(int) * t);
    for (i = 0; i < r; i++) for (j = 0; j < cs[i]; j++) v[k++] = g[i][j];
    qsort(v, t, sizeof(int), c);
    int n = v[t / 2];
    for (i = 0; i < t; i++) { if (v[i] % x != n % x) { free(v); return -1; } a += abs(n - v[i]) / x; }
    free(v);
    return a;
}
