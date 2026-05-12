int compare(const void* a, const void* b) {
    int *t1 = *(int**)a;
    int *t2 = *(int**)b;
    return (t1[1] - t1[0]) - (t2[1] - t2[0]);
}
int minimumEffort(int** t, int n, int* tColSize) {
    qsort(t, n, sizeof(int*), compare);
    int a = 0;
    for (int i = 0; i < n; i++) {
        int t0 = t[i][0], t1 = t[i][1];
        if (a + t0 > t1)  a = a + t0;
        else a = t1;
    }
    return a;
}
