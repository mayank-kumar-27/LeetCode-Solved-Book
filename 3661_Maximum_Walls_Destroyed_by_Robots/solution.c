int cmp(const void* a, const void* b) { return ((int*)a)[0] - ((int*)b)[0]; }
int cW(int* w, int m, long long a, long long b) {
    if (a > b) return 0;
    int lo = 0, hi = m, lo2 = 0, hi2 = m;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (w[mid] < a) lo = mid + 1;
        else hi = mid;
    }
    while (lo2 < hi2) {
        int mid = (lo2 + hi2) / 2;
        if (w[mid] <= b)  lo2 = mid + 1;
        else hi2 = mid;
    }
    return lo2 - lo;
}
int maxWalls(int* robots, int robotsSize, int* distance, int distanceSize, int* walls, int wallsSize) {
    int n = robotsSize, r[n][2];
    for (int i = 0; i < n; i++) {
        r[i][0] = robots[i];
        r[i][1] = distance[i];
    }
    qsort(r, n, sizeof(r[0]), cmp);
    qsort(walls, wallsSize, sizeof(int), cmp);
    int dp[n][2];
    dp[0][0] = cW(walls, wallsSize, (long long)r[0][0] - r[0][1], r[0][0]);
    long long l0 = n > 1 ? r[1][0] - 1 : 2000000000LL;
    dp[0][1] = cW(
        walls, wallsSize, r[0][0],
        (long long)r[0][0] + r[0][1] < l0 ? (long long)r[0][0] + r[0][1] : l0);
    for (int i = 1; i < n; i++) {
        long long cp = r[i][0], cd = r[i][1], pp = r[i - 1][0], pd = r[i - 1][1];
        long long lr = cp - cd > pp + 1 ? cp - cd : pp + 1;
        int wl = cW(walls, wallsSize, lr, cp);
        int ov = cW(walls, wallsSize, lr, pp + pd < cp - 1 ? pp + pd : cp - 1);
        dp[i][0] = dp[i - 1][0] + wl > dp[i - 1][1] + (wl - ov) ? dp[i - 1][0] + wl : dp[i - 1][1] + (wl - ov);
        long long rl = i == n - 1 ? 2000000000LL : r[i + 1][0] - 1;
        int wr = cW(walls, wallsSize, cp, cp + cd < rl ? cp + cd : rl);
        int mx = dp[i - 1][0] > dp[i - 1][1] ? dp[i - 1][0] : dp[i - 1][1];
        dp[i][1] = mx + wr;
    }
    return dp[n - 1][0] > dp[n - 1][1] ? dp[n - 1][0] : dp[n - 1][1];
}