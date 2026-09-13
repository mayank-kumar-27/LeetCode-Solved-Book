class Solution {
    public int largestOverlap(int[][] a, int[][] b) {
        int n = a.length, r = 0;
        for (int x = -n + 1; x < n; x++) for (int y = -n + 1; y < n; y++) {
        int c = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        int p = i + x, q = j + y;
        if (p >= 0 && p < n && q >= 0 && q < n) c += a[i][j] & b[p][q];
        } r = Math.max(r, c);
        } return r;
    }
}