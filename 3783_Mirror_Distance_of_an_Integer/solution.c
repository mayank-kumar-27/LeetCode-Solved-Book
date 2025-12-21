int reverse(int n) {
    int num = 0;
    while (n != 0) {
        num = num * 10 + n % 10;
        n /= 10;
    }
    return num;
}
int mirrorDistance(int n) { return abs(n - reverse(n)); }
