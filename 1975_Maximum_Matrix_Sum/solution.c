long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    long long total_sum = 0;
    int negatives = 0, minimum_sum = INT_MAX;

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            int val = matrix[i][j];
            int abs_val = abs(val);

            total_sum += abs_val;
            minimum_sum = (abs_val < minimum_sum) ? abs_val : minimum_sum;
            negatives += (val < 0);
        }
    }
    return (negatives % 2 == 1) ? total_sum - 2LL * minimum_sum : total_sum;
}
