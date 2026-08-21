class Solution {
    long[] a;
    long gcd(long x, long y) {
        while (y > 0) {
            long t = x % y;
            x = y; y = t;
        } return x;
    }
    long f(long x) {
        long s = 0;
        int n = a.length;
        for (int m = 1; m < (1 << n); m++) {
            long l = 1;
            int c = 0;
            for (int i = 0; i < n; i++) {
                if ((m >> i & 1) == 1) {
                    c++;
                    l = l / gcd(l, a[i]) * a[i];
                    if (l > x) break;
                }
            }
            if (l <= x) s += (c % 2 == 1 ? x / l : -x / l);
        } return s;
    }
    public long findKthSmallest(int[] coins, int k) {
        a = new long[coins.length];
        for (int i = 0; i < a.length; i++) a[i] = coins[i];
        long l = 1, r = 25L * k;
        while (l < r) {
            long m = (l + r) >> 1;
            if (f(m) >= k) r = m;
            else l = m + 1;
        } return l;
    }
}