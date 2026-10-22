class Solution {
    public int minOperations(int[] a) {
        int n = a.length, s = 0;
        while (a[s] != 0) s++;
        boolean u = true, d = true;
        for (int i = 1; i < n; i++) {
            int v = a[(s + i) % n];
            if (v != i) u = false;
            if (v != n - i) d = false;
            if (!u && !d) return -1;
        }
        return u ? Math.min(s, n - s + 2) : Math.min(n - s, s + 2);
    }
}