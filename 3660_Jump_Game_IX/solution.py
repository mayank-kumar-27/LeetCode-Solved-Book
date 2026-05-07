class Solution:
    def maxValue(self, a: List[int]) -> List[int]:
        n, r, p, m = len(a), [0] * len(a), [(0, 0)] * len(a), (-float("inf"), -1)
        for i, x in enumerate(a):
            if x > m[0]:
                m = (x, i)
            p[i] = m
        def f(j, mn, mx):
            v, k = p[j]
            c, t = (v if v <= mn else mx), min(v, mn)
            for i in range(k, j + 1):
                r[i], t = c, min(t, a[i])
            if k:
                f(k - 1, t, c)
        f(n - 1, float("inf"), 0)
        return r
