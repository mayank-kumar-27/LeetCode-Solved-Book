class Solution {
    public int minOperations(int[] a, int x) {
        int n = a.length, l = 0, m = -1;
        long s = 0, t = 0;
        for (int v : a) s += v;
        t = s - x;
        if (t < 0) return -1;
        if (t == 0) return n;
        s = 0;
        for (int r = 0; r < n; r++) {
            s += a[r];
            while (s > t) s -= a[l++];
            if (s == t) m = Math.max(m, r - l + 1);
        } return m < 0 ? -1 : n - m;
    }
}