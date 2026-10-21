class Solution {
    public int diagonalSum(int[][] mat) {
        int n = mat.length, s = 0;
        for (int i = 0; i < n; i++) {
            s += mat[i][i]; s += mat[i][n - 1 - i];
            if (i == n - 1 - i) s -= mat[i][i];
        } return s;
    }
}