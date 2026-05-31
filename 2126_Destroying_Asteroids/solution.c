int comp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
bool asteroidsDestroyed(int m, int* a, int n) {
    qsort(a, n, sizeof(a[0]), comp);
    long long c = m;
    for (int i =0;i<n;i++){
        if (c < a[i]) return false;
        c += a[i];
    }
    return true;
}
