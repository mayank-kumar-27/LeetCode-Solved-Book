int rotatedDigits(int n) {
    int c = 0;
    for (int i = 1; i <= n; i++) {
        int x = i, f = 0;
        while (x) {
            int d = x % 10;
            if (d == 3 || d == 4 || d == 7) { f = -1; break; }
            if (d == 2 || d == 5 || d == 6 || d == 9) { f = 1; }
            x /= 10;
        }
        c += (f == 1);
    }
    return c;
}