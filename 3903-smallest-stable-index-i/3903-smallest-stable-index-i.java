class Solution {
    public int firstStableIndex(int[] a, int k) {
        int n = a.length;
        int[] m = new int[n];
        m[n - 1] = a[n - 1];

        for (int i = n - 2; i >= 0; i--)
            m[i] = Math.min(a[i], m[i + 1]);

        int x = 0;
        for (int i = 0; i < n; i++) {
            x = Math.max(x, a[i]);
            if (x - m[i] <= k) return i;
        }
        return -1;
    }
}