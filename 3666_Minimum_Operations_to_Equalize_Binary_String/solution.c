int minOperations(char* s, int k) {
    int n = strlen(s), z = 0;
    for (int i = 0; i < n; i++) z += ~s[i] & 1;

    if (z == 0) return 0;
    if (n == k) return z == n ? 1 : -1;

    int b = n - k;
    int o = fmax(ceil((double)z / k), ceil((double)(n - z) / b));
    o += ~o & 1;
    int e = fmax(ceil((double)z / k), ceil((double)z / b));
    e += e & 1;

    int r = INT_MAX;
    if ((k & 1) == (z & 1)) r = fmin(r, o);
    if ((~z & 1) == 1) r = fmin(r, e);
    return r == INT_MAX ? -1 : r;
}