char* generateString(char* s, char* t) {
    int n = strlen(s), m = strlen(t);
    int len = n + m - 1;
    char* r = malloc(len + 1);
    char* q = malloc(len + 1);
    
    memset(r, '?', len);
    r[len] = '\0';

    for (int i = 0; i < n; i++) {
        if (s[i] != 'T') continue;
        for (int j = 0; j < m; j++) {
            if (r[i+j] != '?' && r[i+j] != t[j]) { free(r); free(q); return ""; }
            r[i+j] = t[j];
        }
    }

    memcpy(q, r, len + 1);
    for (int i = 0; i < len; i++) if (r[i] == '?') r[i] = 'a';

    for (int i = 0; i < n; i++) {
        if (s[i] != 'F' || strncmp(r + i, t, m) != 0) continue;
        int ok = 0;
        for (int j = i + m - 1; j >= i; j--) {
            if (q[j] == '?') { r[j] = 'b'; ok = 1; break; }
        }
        if (!ok) { free(r); free(q); return ""; }
    }

    free(q);
    return r;
}