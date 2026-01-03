int numOfWays(int n) {
    long MOD = 1000000007;
    long same = 6, diff = 6;

    for (int i = 1; i < n; i++) {
        long same_2 = (same * 2 + diff * 2) % MOD;
        long diff_2 = (same * 2 + diff * 3) % MOD;
        same = same_2; diff = diff_2;
    }
    return (int)((same + diff) % MOD);
}
