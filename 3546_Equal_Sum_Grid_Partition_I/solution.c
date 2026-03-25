bool canPartitionGrid(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    long long t = 0;
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) t += grid[i][j];
    if (t % 2) return 0;
    long long a = t / 2;

    long long s = 0;
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n; j++) s += grid[i][j]; if (s == a) return 1;
    }
    s = 0;
    for (int j = 0; j < n - 1; j++) {
        for (int i = 0; i < m; i++) s += grid[i][j]; if (s == a) return 1;
    }
    return 0;
}