long long minNumberOfSeconds(int mountainHeight, int* workerTimes, int n) {
    long long lo = 1, hi = 1e16;
    while (lo < hi) {
        long long m = (lo + hi) >> 1, s = 0;
        for (int i = 0; i < n; i++) s += (long long)(sqrt(m / (double)workerTimes[i] * 2 + .25) - .5);
        if (s >= mountainHeight) hi = m;
        else lo = m + 1;
    }
    return lo;
}