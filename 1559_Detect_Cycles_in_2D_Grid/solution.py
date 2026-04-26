class Solution:
    def containsCycle(self, g):
        m, n = len(g), len(g[0])
        p = list(range(m * n))
        def f(x):
            if p[x] != x:
                p[x] = f(p[x])
            return p[x]
        for r in range(m):
            for c in range(n):
                id = r * n + c
                if r > 0 and g[r][c] == g[r - 1][c]:
                    if f(id) == f(id - n):
                        return True
                    p[f(id)] = f(id - n)
                if c > 0 and g[r][c] == g[r][c - 1]:
                    if f(id) == f(id - 1):
                        return True
                    p[f(id)] = f(id - 1)
        return False
