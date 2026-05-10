int dfs(int i, int* arr, int n, int t, int* m) {
    if (i == n - 1) return 0;
    if (m[i] != INT_MIN) return m[i];
    int r = INT_MIN;
    for (int j = i + 1; j < n; j++) if (abs(arr[i] - arr[j]) <= t) r = fmax(r, dfs(j, arr, n, t, m) + 1);
    m[i] = r;
    return r;
}
int maximumJumps(int* arr, int n, int t) {
    int* m = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) m[i] = INT_MIN;
    int ans = dfs(0, arr, n, t, m);
    free(m);
    return ans < 0 ? -1 : ans;
}
