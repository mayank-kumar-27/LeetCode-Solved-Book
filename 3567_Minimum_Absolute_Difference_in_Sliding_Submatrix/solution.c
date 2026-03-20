/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int cmp(const void* a, const void* b) { return *(int*)a - *(int*)b; }

int** minAbsDiff(int** g, int m, int* gc, int k, int* rs, int** cs) {
    int n = gc[0], i, j, x, y, p, s = k * k, us;
    int om = m - k + 1, on = n - k + 1;
    int** a = malloc(om * sizeof(int*));
    *cs = malloc(om * sizeof(int));
    *rs = om;

    for (i = 0; i < om; i++) a[i] = malloc(on * sizeof(int)), (*cs)[i] = on;
    for (i = 0; i < om; i++) for (j = 0; j < on; j++) {
        int *t = malloc(s * sizeof(int)), id = 0;
        for (x = i; x < i + k; x++) for (y = j; y < j + k; y++) t[id++] = g[x][y];
        qsort(t, s, sizeof(int), cmp);
        for (p = 0, us = 0; p < s; p++) if (!p || t[p] != t[p - 1]) t[us++] = t[p];
        if (us < 2) a[i][j] = 0;
        else {
            int md = t[1] - t[0];
            for (p = 1; p < us - 1; p++) if (t[p + 1] - t[p] < md) md = t[p + 1] - t[p];
            a[i][j] = md;
        }
        free(t);
    }
    return a;
}