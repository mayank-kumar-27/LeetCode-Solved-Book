/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int** reverseSubmatrix(int** grid, int gridSize, int* gridColSize, int x, int y, int k, int* returnSize, int** returnColumnSizes) {
    for (int i = 0; i < k / 2; i++) {
        int* r1 = grid[x + i];
        int* r2 = grid[x + k - 1 - i];
        for (int j = 0; j < k; j++) { int temp = r1[y + j]; r1[y + j] = r2[y + j]; r2[y + j] = temp; }
    }
    *returnSize = gridSize;
    *returnColumnSizes = (int*)malloc(sizeof(int) * gridSize);
    for (int i = 0; i < gridSize; i++) (*returnColumnSizes)[i] = gridColSize[i];
    return grid;
}