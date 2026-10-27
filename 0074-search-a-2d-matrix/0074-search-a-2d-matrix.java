class Solution {
    public boolean searchMatrix(int[][] mat, int t) {
        int p = mat.length, q = mat[0].length;
        int l = 0, h = p * q - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            int v = mat[m / q][m % q];
            if (v == t) return true;
            else if (v < t) l = m + 1;
            else h = m - 1;
        } return false;
    }
}