int minSwaps(int** grid, int gridSize, int* gridColSize) {
    int z[gridSize], s = 0;
    for (int i = 0; i < gridSize; i++) {
        int c = 0;
        for (int j = gridColSize[i] - 1; j >= 0 && grid[i][j] == 0; j--) c++;
        z[i] = c;
    }
    for (int i = 0; i < gridSize; i++) {
        int r = gridSize - i - 1, j = i;
        while (j < gridSize && z[j] < r) j++;

        if (j == gridSize) return -1;
        while (j > i) {
            int t = z[j]; z[j] = z[j - 1]; z[j - 1] = t;
            j--; s++;
        }
    }
    return s;
}