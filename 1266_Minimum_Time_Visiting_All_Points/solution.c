int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize) {
    int time = 0;
    for (int i = 1; i < pointsSize; i++) {
        int dx = points[i][0] - points[i - 1][0];
        if (dx < 0) dx = -dx;
        int dy = points[i][1] - points[i - 1][1];
        if (dy < 0) dy = -dy;
        
        time += (dx > dy) ? dx : dy;
    }
    return time;
}
