long long reverseNum(long long n) {
    long long num = 0;
    while (n != 0) {
        long long digit = n % 10;
        num = num * 10 + digit;
        n /= 10;
    }
    return num;
}

long long removeZeros(long long n) {
    long long num = 0;
    while (n != 0) {
        if (n % 10 != 0) {
            long long digit = n % 10;
            num = num * 10 + digit;
        }
        n /= 10;
    }
    return reverseNum(num);
}