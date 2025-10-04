int reverse(int x) {
    long long rev = 0;

    while (x != 0) {
        long long value = x % 10;
        rev = rev * 10 + value;
        if (rev > INT_MAX || rev < INT_MIN) {
            return 0;
        }
        x /= 10;
    }

    return (int)rev;
}