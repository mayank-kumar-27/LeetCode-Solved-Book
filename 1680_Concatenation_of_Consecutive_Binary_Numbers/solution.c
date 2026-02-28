#define M 1000000007
int concatenatedBinary(int n) {
    unsigned long long result = 0;
    for (unsigned int i = 1; i <= (unsigned int)n; i++) {
        int b = 32 - __builtin_clz(i);
        result = (result << b) + i;
        if (result >= M) result %= M;
    }
    return (int)result;
}