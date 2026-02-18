int d_to_b(int n, int binary[]) {
    int i = 0;
    while (n > 0) { binary[i++] = n % 2; n /= 2; }
    return i;
}
bool hasAlternatingBits(int n) {
    int binary[32];
    int s = d_to_b(n, binary);
    for (int i = 0; i < s - 1; i++) if (binary[i] == binary[i + 1]) { return false; }
    return true;
}