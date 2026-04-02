int maximumAmount(int** coins, int coinsSize, int* coinsColSize) {
    int r = coinsSize, c = coinsColSize[0];
    int d[r][c][4];
    #define M(a, b) ((a) > (b) ? (a) : (b))

    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) for (int k = 0; k < 4; k++)
    d[i][j][k] = INT_MIN / 2; d[0][0][2] = coins[0][0]; d[0][0][1] = 0;

    for (int i = 1; i < r; i++) {
        int v = coins[i][0];
        for (int k = 0; k < 3; k++) d[i][0][k] = v >= 0 ? d[i - 1][0][k] + v : M(d[i - 1][0][k] + v, d[i - 1][0][k + 1]);
    }
    for (int j = 1; j < c; j++) {
        int v = coins[0][j];
        for (int k = 0; k < 3; k++) d[0][j][k] = v >= 0 ? d[0][j - 1][k] + v : M(d[0][j - 1][k] + v, d[0][j - 1][k + 1]);
    }
    for (int i = 1; i < r; i++) for (int j = 1; j < c; j++) {
        int v = coins[i][j];
        for (int k = 0; k < 3; k++) d[i][j][k] = v >= 0 ? M(d[i - 1][j][k], d[i][j - 1][k]) + v : M(M(d[i - 1][j][k] + v, d[i][j - 1][k] + v), M(d[i - 1][j][k + 1], d[i][j - 1][k + 1]));
    }
    int res = INT_MIN;
    for (int k = 0; k < 4; k++) if (d[r - 1][c - 1][k] > res) res = d[r - 1][c - 1][k];
    return res;
}