typedef long long ll;

typedef struct {
    ll* s;
    int n, c;
    ll a, m;
    ll M;
} Fancy;

ll p(ll b, ll e, ll M) {
    ll r = 1;
    while (e) {
        if (e & 1) r = r * b % M;
        b = b * b % M;
        e >>= 1;
    }
    return r;
}

Fancy* fancyCreate() {
    Fancy* f = malloc(sizeof(Fancy));
    f->c = 1000;
    f->n = 0;
    f->s = malloc(sizeof(ll) * f->c);
    f->a = 0;
    f->m = 1;
    f->M = 1000000007;
    return f;
}

void fancyAppend(Fancy* f, int v) {
    if (f->n == f->c) {
        f->c *= 2;
        f->s = realloc(f->s, sizeof(ll) * f->c);
    }
    ll x = ((v - f->a) % f->M + f->M) % f->M;
    x = x * p(f->m, f->M - 2, f->M) % f->M;
    f->s[f->n++] = x;
}

void fancyAddAll(Fancy* f, int i) { f->a = (f->a + i) % f->M; }

void fancyMultAll(Fancy* f, int k) {
    f->m = f->m * k % f->M;
    f->a = f->a * k % f->M;
}

int fancyGetIndex(Fancy* f, int i) {
    if (i >= f->n) return -1;
    return (f->s[i] * f->m + f->a) % f->M;
}

void fancyFree(Fancy* f) {
    free(f->s);
    free(f);
}