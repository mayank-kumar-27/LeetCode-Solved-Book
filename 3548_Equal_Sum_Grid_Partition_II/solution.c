static bool solve(int** g, int n, int m) {
    long long bot = 0, top = 0;
    int* bf = calloc(100001, sizeof(int)); int* tf = calloc(100001, sizeof(int));

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) 
    { bot += g[i][j]; bf[g[i][j]]++; }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            bot -= g[i][j];
            bf[g[i][j]]--;
            top += g[i][j];
            tf[g[i][j]]++;
        }
        if (top == bot) { free(bf); free(tf); return true; }

        long long dt = top - bot;
        if (dt > 0 && dt <= 100000) {
            int h = i + 1, w = m;
            if (h > 1 && w > 1) {
                if (tf[dt]) { free(bf); free(tf); return true; }
            } else if (h > 1 && w == 1) {
                if (g[0][0] == dt || g[i][0] == dt) { free(bf); free(tf); return true; }
            } else if (h == 1 && w > 1) {
                if (g[0][0] == dt || g[0][w - 1] == dt) { free(bf); free(tf); return true; }
            }
        }

        long long db = bot - top;
        if (db > 0 && db <= 100000) {
            int h = n - i - 1, w = m;
            if (h > 1 && w > 1) {
                if (bf[db]) { free(bf); free(tf); return true; }
            } else if (h > 1 && w == 1) {
                if (g[i + 1][0] == db || g[n - 1][0] == db) { free(bf); free(tf); return true; }
            } else if (h == 1 && w > 1) {
                if (g[n - 1][0] == db || g[n - 1][w - 1] == db) { free(bf); free(tf); return true; }
            }
        }
    }
    free(bf);
    free(tf);
    return false;
}

bool canPartitionGrid(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize, m = gridColSize[0];

    if (solve(grid, n, m)) return true;

    int** mat = malloc(m * sizeof(int*));
    for (int j = 0; j < m; j++) {
        mat[j] = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) mat[j][i] = grid[i][j];
    }

    bool res = solve(mat, m, n);
    for (int j = 0; j < m; j++) free(mat[j]);
    free(mat);
    return res;
}