int closestTarget(char** w, int ws, char* target, int si) {
    int a = ws, n = ws;
    for (int i = 0; i < n; ++i) if (strcmp(w[i], target) == 0) { int d = abs(i - si); a = fmin(a, fmin(d, n - d)); }
    return a < n ? a : -1;
}
