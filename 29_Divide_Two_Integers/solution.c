int divide(int x, int y) {
    if (y == 0) return INT_MAX;
    if (x == y) return 1;

    bool p = ((x < 0) == (y < 0));
    long long a = x;
    long long b = y;

    if (a < 0) a = -a;
    if (b < 0) b = -b;

    long long r = 0;
    while (a >= b) {
        int q = 0;
        while (a >= (b << (q + 1))) q++;
        r += (1LL << q);
        a -= (b << q);
    }

    if (r == (1LL << 31) && p) return INT_MAX;
    return p ? (int)r : (int)-r;
}