bool findRotation(int** a, int n, int* ac, int** b, int m, int* bc) {
    for (int k = 0; k < 4; k++) {
        int ok = 1;
        for (int i = 0; i < n && ok; i++) for (int j = 0; j < n; j++)
        if (a[i][j] != b[i][j]) { ok = 0; break; }
        if (ok) return true;
        int** t = malloc(n * sizeof(int*));
        for (int i = 0; i < n; i++) t[i] = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        t[j][n - 1 - i] = a[i][j];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) a[i][j] = t[i][j];
            free(t[i]);
        }
        free(t);
    }
    return false;
}
