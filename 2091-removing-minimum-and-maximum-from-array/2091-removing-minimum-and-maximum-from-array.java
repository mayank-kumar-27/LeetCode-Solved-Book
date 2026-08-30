class Solution {
    public int minimumDeletions(int[] a) {
        int n = a.length, x = 0, y = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[x]) x = i;
            if (a[i] > a[y]) y = i;
        }
        int l = Math.min(x, y), r = Math.max(x, y);
        return Math.min(r + 1, Math.min(n - l, l + 1 + n - r));
    }
}