int comp(const void* a, const void* b) { return (*(int*)b - *(int*)a); }
int minimumCost(int* cost, int n) {
    qsort(cost, n, sizeof(int), comp);
    int r = 0;
    for (int i = 0; i < n; ++i) if (i % 3 != 2) r += cost[i];
    return r;
}
