/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** rotateGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes){
    int m = gridSize;
    int n = gridColSize[0];
    int nl = (m / 2 < n / 2) ? (m / 2) : (n / 2);
    for (int l = 0; l < nl; l++) {
        int maxSize = 2 * (m + n);
        int* r = (int*)malloc(sizeof(int) * maxSize);
        int* c = (int*)malloc(sizeof(int) * maxSize);
        int* val = (int*)malloc(sizeof(int) * maxSize);
        int idxCount = 0;
        for (int i = l; i < m - l - 1; i++) {
            r[idxCount] = i;
            c[idxCount] = l;
            val[idxCount] = grid[i][l];
            idxCount++;
        }
        for (int j = l; j < n - l - 1; j++) {
            r[idxCount] = m - l - 1;
            c[idxCount] = j;
            val[idxCount] = grid[m - l - 1][j];
            idxCount++;
        }
        for (int i = m - l - 1; i > l; i--) {
            r[idxCount] = i;
            c[idxCount] = n - l - 1;
            val[idxCount] = grid[i][n - l - 1];
            idxCount++;
        }
        for (int j = n - l - 1; j > l; j--) {
            r[idxCount] = l;
            c[idxCount] = j;
            val[idxCount] = grid[l][j];
            idxCount++;
        }
        int total = idxCount;
        int kk = k % total;
        for (int i = 0; i < total; i++) {
            int idx = (i + total - kk) % total;
            grid[r[i]][c[i]] = val[idx];
        }
        free(r);
        free(c);
        free(val);
    }
    *returnSize = gridSize;
    *returnColumnSizes = (int*)malloc(sizeof(int) * gridSize);
    for (int i = 0; i < gridSize; i++) (*returnColumnSizes)[i] = gridColSize[i];
    return grid;
}
