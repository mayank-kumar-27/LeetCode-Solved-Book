int** sortTheStudents(int** score, int scoreSize, int* scoreColSize, int k, int* returnSize, int** returnColumnSizes) {
    *returnSize = scoreSize;
    *returnColumnSizes = (int*)malloc(scoreSize * sizeof(int));
    for (int i = 0; i < scoreSize; i++) (*returnColumnSizes)[i] = *scoreColSize;

    for (int i = 0; i < scoreSize - 1; i++) {
        for (int j = 0; j < scoreSize - i - 1; j++) {
            if (score[j][k] < score[j + 1][k]) {
                int* temp = score[j];
                score[j] = score[j + 1];
                score[j + 1] = temp;
            }
        }
    }
    return score;
}