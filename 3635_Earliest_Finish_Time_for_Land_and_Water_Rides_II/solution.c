#define mn(a, b) ((a) < (b) ? (a) : (b))
#define mx(a, b) ((a) > (b) ? (a) : (b))

int f(int* a, int n, int* b, int* c, int m, int* d) {
    int x = INT_MAX, y = INT_MAX;
    for (int i = 0; i < n; i++) x = mn(x, a[i] + b[i]);
    for (int i = 0; i < m; i++) y = mn(y, mx(c[i], x) + d[i]);
    return y;
}

int earliestFinishTime(int* a, int n, int* b, int bn, int* c, int m, int* d, int dn) {
    return mn(f(a, n, b, c, m, d), f(c, m, d, a, n, b));
}
