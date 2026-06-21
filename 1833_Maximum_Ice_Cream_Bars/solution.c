int maxIceCream(int* c, int cs, int k) {
    int m = 0, r = 0;
    for (int i = 0; i < cs; i++) m = m > c[i] ? m : c[i];
    int* f = (int*)calloc((m + 1), sizeof(int));

    for (int i = 0; i < cs; i++) f[c[i]]++;
    for (int i = 1; i <= m && k >= i; i++) {
        int x = f[i] > k / i ? k / i : f[i];
        r += x;
        k -= x * i;
    }
    free(f);
    return r;
}