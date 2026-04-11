class Solution:
    def minimumDistance(self, a: List[int]) -> int:
        n, m = len(a), max(a)
        p = [(-1, -1) for _ in range(m + 1)]
        r = 1 << 32
        for i, x in enumerate(a):
            if p[x][1] != -1:
                r = min(r, (i - p[x][1]) << 1)
            p[x] = (i, p[x][0])
        return -1 if r == 1 << 32 else r
