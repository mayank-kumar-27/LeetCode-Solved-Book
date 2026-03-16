/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int f(int** g, int r, int c, int k) {
    int x = g[r][c];
    for (int i = 0; i < k; i++) {
        r++;
        x += g[r][c + i + 1];
        x += g[r][c - i - 1];
    }
    for (int i = k - 1; i >= 0; i--) {
        r++;
        x += g[r][c + i];
        if (i > 0) x += g[r][c - i];
    }
    return x;
}

int exist(int *a, int s, int v) {
    for (int i = 0; i < s; i++) if (a[i] == v) return 1;
    return 0;
}

void add(int *a, int *s, int v) {
    if (exist(a, *s, v)) return;
    if (*s < 3) a[(*s)++] = v;
    else {
        int mi = 0;
        for (int i = 1; i < 3; i++) if (a[i] < a[mi]) mi = i;
        if (v > a[mi]) a[mi] = v;
    }
}

void sort3(int *a, int s) {
    for (int i = 0; i < s; i++) for (int j = i + 1; j < s; j++)
    if (a[i] < a[j]) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
}

int* getBiggestThree(int** g, int m, int* cs, int* rs) {
    int n = cs[0];
    int *b = malloc(3 * sizeof(int));
    int s = 0;
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            add(b, &s, g[r][c]);
            int k = 1;
            while (c - k >= 0 && c + k < n && r + 2 * k < m) {
                int v = f(g, r, c, k);
                add(b, &s, v);
                k++;
            }
        }
    }
    sort3(b, s);
    *rs = s;
    return b;
}