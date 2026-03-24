/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int** constructProductMatrix(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int MOD = 12345;
    int rows = gridSize;
    int cols = gridColSize[0];
    int** prod_matrix = (int**)malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++) {
        prod_matrix[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) prod_matrix[i][j] = 1;
    }
    long long prefix = 1;
    for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) {
        prod_matrix[i][j] = prefix;
        prefix = (prefix * grid[i][j]) % MOD;
    }
    long long suffix = 1;
    for (int i = rows - 1; i >= 0; i--) for (int j = cols - 1; j >= 0; j--) {
        prod_matrix[i][j] = (prod_matrix[i][j] * suffix) % MOD;
        suffix = (suffix * grid[i][j]) % MOD;
    }
    *returnSize = rows;
    *returnColumnSizes = (int*)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) (*returnColumnSizes)[i] = cols;
    return prod_matrix;
}