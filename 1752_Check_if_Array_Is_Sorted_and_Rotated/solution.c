bool check(int* nums, int n) {
    for (int i = 0; i < n; i++) {
        int* f = (int*)malloc(n * sizeof(int));
        int idx = 0;
        for (int j = i; j < n; j++) f[idx++] = nums[j];
        for (int j = 0; j < i; j++) f[idx++] = nums[j];
        bool s = true;
        for (int j = 0; j < n - 1; j++) if (f[j] > f[j + 1]) { s = false; break; }
        free(f);
        if (s) return true;
    }
    return false;
}
