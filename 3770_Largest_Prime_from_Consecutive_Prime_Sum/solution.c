int largestPrime(int n) {
    if (n < 2) return 0;
    
    bool* is_prime = (bool*)malloc((n + 1) * sizeof(bool));
    for (int i = 0; i <= n; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++)
        if (is_prime[i]) for (int j = i * i; j <= n; j += i) is_prime[j] = false;
    
    int* primes = (int*)malloc((n + 1) * sizeof(int));
    int count = 0;
    for (int i = 2; i <= n; i++) if (is_prime[i]) primes[count++] = i;

    int result = 0, sum = 0;
    for (int i = 0; i < count; i++) {
        sum += primes[i];
        if (sum > n) break;
        if (is_prime[sum]) result = sum;
    }

    free(is_prime);
    free(primes);
    return result;
}