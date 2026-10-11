class Solution {
    public int sumOfSquares(int[] a) {
        int n = a.length;
        int r = 0;
        for (int i = 0; i < n; ++i) if (n % (i + 1) == 0) r += a[i] * a[i];
        return r;
    }
}