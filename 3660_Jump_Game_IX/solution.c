/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int v, i;
} P;
void f(int* a, int* r, P* p, int j, int mn, int mx) {
    int v = p[j].v, k = p[j].i;
    int c = (v <= mn) ? v : mx;
    int t = (v < mn) ? v : mn;

    for (int i = k; i <= j; i++) {
        r[i] = c;
        if (a[i] < t) t = a[i];
    }
    if (k) f(a, r, p, k - 1, t, c);
}
int* maxValue(int* a, int n, int* s) {
    int* r = calloc(n, sizeof(int));
    P *p = malloc(n * sizeof(P)), m = {INT_MIN, -1};
    for (int i = 0; i < n; i++) {
        if (a[i] > m.v) m = (P){a[i], i};
        p[i] = m;
    }
    f(a, r, p, n - 1, INT_MAX, 0);
    free(p);
    *s = n;
    return r;
}
