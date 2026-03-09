#define M 1000000007

long c(int n, int k, long* f, long* i) {
    return k < 0 || k > n ? 0 : f[n] * i[k] % M * i[n - k] % M;
}

long g(int n, int k, int l, long* f, long* i) {
    if (k <= 0 || k > n) return 0;
    long a = 0;
    for (int j = 0; j <= (n - k) / l; j++) {
        long x = c(k, j, f, i) * c(n - j * l - 1, k - 1, f, i) % M;
        a = (a + (j & 1 ? M - x : x)) % M;
    }
    return a;
}

int numberOfStableArrays(int z, int o, int l) {
    int t = z + o, mk = z < o + 1 ? z : o + 1;
    long a = 0, *f = calloc(t + 1, 8), *i = calloc(t + 1, 8), *v = calloc(mk + 3, 8);
    f[0] = i[0] = 1;
    for (int j = 1; j <= t; j++) f[j] = f[j - 1] * j % M;
    long b = f[t], e = M - 2, r = 1;
    while (e) { if (e & 1) r = r * b % M; b = b * b % M; e >>= 1; }
    i[t] = r;
    for (int j = t - 1; j >= 1; j--) i[j] = i[j + 1] * (j + 1) % M;
    for (int k = 1; k <= mk + 1; k++) v[k] = g(o, k, l, f, i);
    for (int k = 1; k <= mk; k++) {
        long fz = g(z, k, l, f, i);
        if (fz) a = (a + fz * (v[k - 1] + 2 * v[k] + v[k + 1])) % M;
    }
    free(f); free(i); free(v);
    return a;
}