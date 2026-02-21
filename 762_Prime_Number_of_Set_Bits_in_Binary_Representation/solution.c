int count_ones(int n) {
    int count = 0;
    while (n > 0) { if (n % 2 == 1) count++; n /= 2; }
    return count;
}
bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
    return true;
}
int countPrimeSetBits(int left, int right) {
    int count = 0;
    for (int i = left; i <= right; i++) if (is_prime(count_ones(i))) count++;
    return count;
}