typedef struct n{
    int v;
    struct n* x;
}n;

#define M 100003

n* h[M];

int f(int v){ return v % M; }

int e(int v){
    n* c = h[f(v)];
    while(c){
        if(c->v == v) return 1;
        c = c->x;
    }
    return 0;
}

void i(int v){
    int k = f(v);
    n* t = malloc(sizeof(n));
    t->v = v;
    t->x = h[k];
    h[k] = t;
}

int longestCommonPrefix(int* a, int n, int* b, int m) {
    for(int j=0;j<M;j++) h[j]=0;

    int r = 0;

    for(int j=0;j<n;j++)
        for(int v=a[j]; v && !e(v); v/=10)
            i(v);

    for(int j=0;j<m;j++){
        int v = b[j], c = 0;

        while(v && !e(v)) v/=10;

        for(int t=v; t; t/=10) c++;

        if(c > r) r = c;
    }

    return r;
}
