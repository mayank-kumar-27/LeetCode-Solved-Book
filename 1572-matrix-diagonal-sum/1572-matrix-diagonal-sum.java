class Solution {
    public int diagonalSum(int[][] mat) {
        int m = mat.length, n = mat[0].length, s = 0;
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
            if (i == j || i + j == n - 1) s += mat[i][j];
        } return s;
    }
}