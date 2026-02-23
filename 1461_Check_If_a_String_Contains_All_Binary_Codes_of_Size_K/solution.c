bool hasAllCodes(char* s, int k) {
    int n = strlen(s);
    if (n < k + (1 << k) - 1) return false;

    int t = 1 << k;
    bool* v = calloc(t, sizeof(bool));
    int m = t - 1, x = 0, c = 0;
    for (int i = 0; i < n; i++) {
        x = ((x << 1) & m) | (s[i] - '0');
        if (i >= k - 1 && !v[x]) { v[x] = true; c++; }
    }
    free(v);
    return c == t;
}