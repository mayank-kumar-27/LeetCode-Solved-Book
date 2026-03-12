typedef struct { int *p, *r, c; } D;

D* I(int n) {
    D* d = malloc(sizeof(D));
    d->p = malloc(n * sizeof(int));
    d->r = calloc(n, sizeof(int));
    d->c = n;
    for (int i = 0; i < n; ++i) d->p[i] = i;
    return d;
}

int F(D* d, int x) { 
    return d->p[x] == x ? x : (d->p[x] = F(d, d->p[x])); 
}

int U(D* d, int a, int b) {
    int x = F(d, a), y = F(d, b), t;
    if (x == y) return 0;
    if (d->r[x] < d->r[y]) { t = x; x = y; y = t; }
    d->p[y] = x;
    d->r[x] += d->r[x] == d->r[y];
    d->c--;
    return 1;
}

void X(D* d) { 
    free(d->p); free(d->r); free(d); 
}

int C(int n, int** e, int s, int k, int x) {
    D* d = I(n);
    int y = 0, a;
    for (int i = 0; i < s; ++i) 
        if (e[i][3] && (e[i][2] < x || !U(d, e[i][0], e[i][1]))) { X(d); return 0; }
    for (int i = 0; i < s; ++i) 
        if (!e[i][3] && e[i][2] >= x) U(d, e[i][0], e[i][1]);
    for (int i = 0; i < s; ++i) 
        if (!e[i][3] && e[i][2] < x && 2 * e[i][2] >= x && U(d, e[i][0], e[i][1]) && ++y > k) { X(d); return 0; }
    
    a = d->c == 1;
    X(d);
    return a;
}

int maxStability(int n, int** e, int s, int* cs, int k) {
    D* d = I(n);
    int l = 1, h = 200000, a = -1, m;
    
    for (int i = 0; i < s; ++i) 
        if (e[i][3] && !U(d, e[i][0], e[i][1])) { X(d); return -1; }
    X(d);
    
    while (l <= h) {
        m = l + (h - l) / 2;
        if (C(n, e, s, k, m)) { a = m; l = m + 1; } 
        else h = m - 1;
    }
    return a;
}