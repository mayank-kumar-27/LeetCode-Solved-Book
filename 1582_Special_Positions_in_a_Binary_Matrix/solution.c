int numSpecial(int** mat, int matSize, int* matColSize) {
    int res = 0, m = matSize, n = *matColSize;
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
        if (!mat[i][j]) continue;
        int rs = 0, cs = 0;
        for (int k = 0; k < n; k++) rs += mat[i][k];
        for (int k = 0; k < m; k++) cs += mat[k][j];
        res += (rs == 1 && cs == 1);
    }
    return res;
}