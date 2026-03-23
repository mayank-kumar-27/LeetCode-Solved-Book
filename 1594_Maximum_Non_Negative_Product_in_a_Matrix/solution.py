class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        M = 10**9 + 7
        mn = [[float("inf")] * n for _ in range(m)]
        mx = [[float("-inf")] * n for _ in range(m)]
        mn[0][0] = mx[0][0] = grid[0][0]
        for i in range(m):
            for j in range(n):
                if i or j:
                    v = grid[i][j]
                    a = []
                    if i: a += [mn[i - 1][j] * v, mx[i - 1][j] * v]
                    if j: a += [mn[i][j - 1] * v, mx[i][j - 1] * v]
                    mn[i][j], mx[i][j] = min(a), max(a)
        r = mx[-1][-1]
        return r % M if r >= 0 else -1