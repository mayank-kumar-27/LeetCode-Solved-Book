double champagneTower(int poured, int query_row, int query_glass) {
    double t[102][102] = {};
    t[0][0] = (double)poured;
    for (int i = 0; i <= query_row; i++) for (int j = 0; j <= i; j++) {
        double r = (t[i][j] - 1.0) / 2.0;
        if (r > 0) { t[i + 1][j] += r; t[i + 1][j + 1] += r; }
    }
    return 1 > t[query_row][query_glass] ? t[query_row][query_glass] : 1;
}