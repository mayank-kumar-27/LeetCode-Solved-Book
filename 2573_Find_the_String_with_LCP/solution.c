char* findTheString(int** lcp, int lcpSize, int* lcpColSize) {
    int n = lcpSize;
    char* s = (char*)malloc((n + 1) * sizeof(char));
    if (!s) return "";

    for (int i = 0; i < n; i++) s[i] = 'X';
    s[n] = '\0';

    int id = -1;
    for (int i = 0; i < n; i++) {
        if (lcp[i][i] != n - i) { free(s); return ""; }
        if (s[i] >= 'a') continue;
        id++;
        if (id >= 26) { free(s); return ""; }
        for (int j = i; j < n; j++) if (lcp[i][j]) s[j] = 'a' + id;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int x = lcp[i][j];
            if (x != lcp[j][i] || x + i > n) { free(s); return ""; }
            int y = (i < n - 1) ? lcp[i + 1][j + 1] : 0;
            if (s[i] == s[j])  y += 1;
            else y = 0;
            if (x != y) { free(s); return ""; }
        }
    }
    return s;
}