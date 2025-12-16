void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0];

    int* zeroRows = (int*)calloc(rows, sizeof(int));
    int* zeroCols = (int*)calloc(cols, sizeof(int));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                zeroRows[i] = 1;
                zeroCols[j] = 1;
            }
        }
    }

    for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) if (zeroRows[i] || zeroCols[j]) matrix[i][j] = 0;

    free(zeroRows);
    free(zeroCols);
}