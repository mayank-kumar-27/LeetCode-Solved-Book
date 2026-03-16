class Solution:
    def getBiggestThree(self, g):
        m, n = len(g), len(g[0])
        b = set()

        def f(r, c, k):
            x = g[r][c]

            for i in range(k):
                r += 1
                x += g[r][c + i + 1]
                x += g[r][c - i - 1]

            for i in range(k - 1, -1, -1):
                r += 1
                x += g[r][c + i]
                if i > 0:
                    x += g[r][c - i]
            return x

        for r in range(m):
            for c in range(n):
                b.add(g[r][c])
                k = 1
                while c - k >= 0 and c + k < n and r + 2 * k < m:
                    b.add(f(r, c, k))
                    k += 1

        return sorted(b, reverse=True)[:3]