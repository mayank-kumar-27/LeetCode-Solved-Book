static int g(char **r, size_t *c, size_t n) {
    if (n <= *c) return 1;
    while (*c < n) *c <<= 1;
    char *t = realloc(*r, *c);
    if (!t) return 0;
    *r = t;
    return 1;
}
char *processStr(const char *s) {
    size_t n = 0, c = 16;
    char *r = malloc(c);
    if (!r) return NULL;
    for (*r = 0; *s; s++) {
        if (*s == '*') { if (n) r[--n] = 0;
        } else if (*s == '#') {
            if (!g(&r, &c, n * 2 + 1)) return free(r), NULL;
            memcpy(r + n, r, n);
            r[n *= 2] = 0;
        } else if (*s == '%') {
            for (size_t i = 0; i < n / 2; i++) {
                char t = r[i];
                r[i] = r[n - 1 - i];
                r[n - 1 - i] = t;
            }
        } else {
            if (!g(&r, &c, n + 2)) return free(r), NULL;
            r[n++] = *s;
            r[n] = 0;
        }
    }
    return r;
}