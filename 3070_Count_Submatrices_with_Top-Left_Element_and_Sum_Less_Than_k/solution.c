int countSubmatrices(int** grid, int gridSize, int* gridColSize, int k) {
    int r = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            int u = (i > 0) ? grid[i - 1][j] : 0;
            int l = (j > 0) ? grid[i][j - 1] : 0;
            int d = (i > 0 && j > 0) ? grid[i - 1][j - 1] : 0;
            grid[i][j] = grid[i][j] + u + l - d;

            if (grid[i][j] <= k) r += 1;
            else { if (j == 0) return r; break; }
        }
    }
    return r;
}