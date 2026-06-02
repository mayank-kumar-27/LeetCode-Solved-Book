#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int earliestFinishTime(int* lStartTime, int n, int* lDuration, int lDurationSize, int* wStartTime, int m, int* wDuration, int wDurationSize) {
    int r = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int l = lStartTime[i] + lDuration[i];
            int lw = MAX(l, wStartTime[j]) + wDuration[j];
            r = MIN(r, lw);

            int w = wStartTime[j] + wDuration[j];
            int wl = MAX(w, lStartTime[i]) + lDuration[i];
            r = MIN(r, wl);
        }
    }
    return r;
}
