class Solution {
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        int m = mat.length, n = mat[0].length;
        if (m * n != r * c) return mat;

        int[][] mat2 = new int[r][c]; int k = 0;
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
            mat2[k / c][k % c] = mat[i][j]; k++;
        } return mat2;
    }
}