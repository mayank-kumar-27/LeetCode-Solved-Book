int cmp(const void* a, const void* b) { return *(int*)b - *(int*)a; }
int largestSubmatrix(int** matrix, int m, int* colSize) {
    int n = colSize[0], a = 0;
    int* h = calloc(n, sizeof(int));
    int* s = malloc(n * sizeof(int));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) h[j] = matrix[i][j] ? h[j] + 1 : 0;
        for (int j = 0; j < n; j++) s[j] = h[j];
        qsort(s, n, sizeof(int), cmp);
        for (int j = 0; j < n && s[j]; j++) if (s[j] * (j + 1) > a) a = s[j] * (j + 1);
    }
    free(h); free(s);
    return a;
}