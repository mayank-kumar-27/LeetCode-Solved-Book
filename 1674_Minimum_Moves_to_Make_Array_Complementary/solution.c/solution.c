int minMoves(int* nums, int n, int limit) {
    int* d = (int*)calloc(2 * limit + 2, sizeof(int));
    for (int i = 0; i < n / 2; i++) {
        int a = fmin(nums[i], nums[n - 1 - i]);
        int b = fmax(nums[i], nums[n - 1 - i]);
        d[2] += 2;
        d[a + 1] -= 1;
        d[a + b] -= 1;
        d[a + b + 1] += 1;
        d[b + limit + 1] += 1;
    }
    int m = n, cp = 0;
    for (int c = 2; c <= 2 * limit; c++) {
        cp += d[c];
        if (cp < m) m = cp;
    }
    free(d);
    return m;
}