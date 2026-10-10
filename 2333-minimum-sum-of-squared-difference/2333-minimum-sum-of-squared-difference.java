class Solution {
    public long minSumSquareDiff(int[] a, int[] b, int x, int y) {
        long k = (long) x + y, s = 0;
        int n = a.length;

        for (int i = 0; i < n; i++) {
            a[i] = Math.abs(a[i] - b[i]);
            s += a[i];
        }
        if (s <= k) return 0;

        Arrays.sort(a);
        int[] d = new int[n + 1];
        for (int i = 0; i < n; i++) d[i] = a[n - 1 - i];

        for (int i = 1; i <= n; i++) {
            long c = (long) (d[i - 1] - d[i]) * i;
            if (c > k) {
                long q = k / i, r = k % i, h = d[i - 1] - q;
                long z = h * h * (i - r) + (h - 1) * (h - 1) * r;
                for (int j = i; j < n; j++) z += (long) d[j] * d[j];
                return z;
            }
            k -= c;
        }
        return 0;
    }
}