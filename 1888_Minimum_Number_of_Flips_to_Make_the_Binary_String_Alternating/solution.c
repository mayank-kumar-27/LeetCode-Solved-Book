int minFlips(char* s) {
    int n = strlen(s), alt1 = 0, alt2 = 0, res = INT_MAX;
    char* t = malloc(2 * n + 1);
    strcpy(t, s); strcpy(t + n, s);
    for (int i = 0; i < 2 * n; i++) {
        alt1 += t[i] - '0' != i % 2;
        alt2 += t[i] - '0' != (i + 1) % 2;
        if (i >= n) { alt1 -= t[i - n] - '0' != (i - n) % 2; alt2 -= t[i - n] - '0' != (i - n + 1) % 2; }
        if (i >= n - 1) res = fmin(res, fmin(alt1, alt2));
    }
    free(t);
    return res;
}