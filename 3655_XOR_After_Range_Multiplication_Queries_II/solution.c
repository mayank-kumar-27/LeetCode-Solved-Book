#define MOD 1000000007LL
typedef long long ll;

ll powmod(ll b, ll e, ll m) {
    ll r = 1; b %= m;
    while (e > 0) {
        if (e & 1) r = r * b % m;
        b = b * b % m;
        e >>= 1;
    }
    return r;
}

int xorAfterQueries(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    int n = numsSize, lim = 1;
    while ((lim + 1) * (lim + 1) <= n) lim++;

    for (int q = 0; q < queriesSize; q++) {
        int l = queries[q][0], r = queries[q][1], k = queries[q][2], v = queries[q][3];
        if (k >= lim)
            for (int i = l; i <= r; i += k)
                nums[i] = (ll)nums[i] * v % MOD;
    }

    ll d[numsSize];
    for (int k = 1; k < lim; k++) {
        int cnt = 0;
        for (int q = 0; q < queriesSize; q++)
            if (queries[q][2] == k) cnt++;
        if (!cnt) continue;

        for (int i = 0; i < n; i++) d[i] = 1;

        for (int q = 0; q < queriesSize; q++) {
            int l = queries[q][0], r = queries[q][1], v = queries[q][3];
            if (queries[q][2] != k) continue;
            d[l] = d[l] * v % MOD;
            int x = l + ((r - l) / k + 1) * k;
            if (x < n) d[x] = d[x] * powmod(v, MOD - 2, MOD) % MOD;
        }

        for (int i = 0; i < n; i++) {
            if (i >= k) d[i] = d[i] * d[i - k] % MOD;
            nums[i] = (ll)nums[i] * d[i] % MOD;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) ans ^= nums[i];
    return ans;
}
