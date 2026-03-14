char* getHappyString(int n, int k) {
    int t = 3 * pow(2, n - 1);
    if (k > t) {
        char *e = malloc(1);
        e[0] = '\0';
        return e;
    }
    k--;

    char *r = malloc(n + 1);
    char p = 0;

    for (int i = 0; i < n; i++) {
        int b = pow(2, n - i - 1);
        char c[3];
        int m = 0;
        for (char x = 'a'; x <= 'c'; x++) if (x != p) c[m++] = x;

        int j = k / b;
        r[i] = c[j];

        p = c[j];
        k %= b;
    }
    r[n] = '\0';
    return r;
}