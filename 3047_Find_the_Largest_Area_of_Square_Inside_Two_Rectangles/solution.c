long long largestSquareArea(int** bottomLeft, int bottomLeftSize, int* bottomLeftColSize, int** topRight, int topRightSize, int* topRightColSize) {
    long long max_area = 0;
    for (int i = 0; i < bottomLeftSize; i++)
        for (int j = i + 1; j < bottomLeftSize; j++) {
            long long l = bottomLeft[i][0] > bottomLeft[j][0] ? bottomLeft[i][0] : bottomLeft[j][0];
            long long r = topRight[i][0] < topRight[j][0] ? topRight[i][0] : topRight[j][0];
            long long b = bottomLeft[i][1] > bottomLeft[j][1] ? bottomLeft[i][1] : bottomLeft[j][1];
            long long t = topRight[i][1] < topRight[j][1] ? topRight[i][1] : topRight[j][1];
            if (l < r && b < t) {
                long long s = (r - l < t - b) ? r - l : t - b;
                max_area = (s * s > max_area) ? s * s : max_area;
            }
        }
    return max_area;
}
