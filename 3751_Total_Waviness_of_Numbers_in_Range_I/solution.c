int g(int x) {
    char s[20];
    snprintf(s, sizeof(s), "%d", x);
    int w = 0;
    int n = strlen(s);
    for (int i = 1; i < n - 1; i++) {
        int p = s[i] > s[i - 1] && s[i] > s[i + 1];
        int v = s[i] < s[i - 1] && s[i] < s[i + 1];
        if (p || v) w++;
    }
    return w;
}
int totalWaviness(int a, int b) {
    int t = 0;
    for (int i = a; i <= b; i++) t += g(i);
    return t;
}
