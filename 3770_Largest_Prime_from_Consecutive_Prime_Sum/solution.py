class Solution:
    def largestPrime(self, n: int) -> int:
        if n < 2: return 0

        is_prime = [True] * (n + 1)
        is_prime[0] = is_prime[1] = False

        for i in range(2, int(n**0.5) + 1):
            if is_prime[i]:
                for j in range(i * i, n + 1, i):
                    is_prime[j] = False

        primes = [i for i in range(2, n + 1) if is_prime[i]]
        result, sum_val = 0, 0

        for prime in primes:
            sum_val += prime

            if sum_val > n: break

            if is_prime[sum_val]: result = sum_val

        return result