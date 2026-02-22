int binaryGap(int n) {
    if (__builtin_popcount(n) == 1) return 0;
    n >>= __builtin_ctz(n);

    int max = 0, gap = 0;
    while (n) { if (n & 1) { max = max > gap ? max : gap; gap = 0; } else gap++; n >>= 1; }
    return max + 1;
}