class Solution:
    def numberOfStableArrays(self, z: int, o: int, l: int) -> int:
        m = 10**9 + 7
        t = z + o
        f, p = [1] * (t + 1), [1] * (t + 1)
        for i in range(1, t + 1): f[i] = f[i - 1] * i % m
        p[t] = pow(f[t], m - 2, m)
        for i in range(t - 1, 0, -1): p[i] = p[i + 1] * (i + 1) % m
        c = lambda n, k: f[n] * p[k] * p[n - k] % m if 0 <= k <= n else 0
        g = lambda n, k: sum((-1)**j * c(k, j) * c(n - j * l - 1, k - 1) for j in range((n - k) // l + 1)) % m if 0 < k <= n else 0
        v = [g(o, k) for k in range(min(z, o + 1) + 3)]
        return sum(g(z, k) * (v[k - 1] + 2 * v[k] + v[k + 1]) for k in range(1, min(z, o + 1) + 1)) % m