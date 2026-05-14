bool isGood(int* nums, int n) {
    int* c = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        int a = nums[i];
        if (a < 1 || a >= n) { free(c); return false; }
        if (a < n - 1 && c[a] > 0) { free(c); return false; }
        if (a == n - 1 && c[a] > 1) { free(c); return false; }
        c[a]++;
    }
    free(c);
    return true;
}
