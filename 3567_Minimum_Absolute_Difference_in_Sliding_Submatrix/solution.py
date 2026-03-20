class Solution:
    def minAbsDiff(self, grid: list[list[int]], k: int) -> list[list[int]]:
        m, n = len(grid), len(grid[0])
        ans = [[0] * (n - k + 1) for _ in range(m - k + 1)]
        for i in range(m - k + 1):
            for j in range(n - k + 1):
                r = sorted(set(grid[x][y] for x in range(i, i + k) for y in range(j, j + k)))
                if len(r) <= 1: ans[i][j] = 0
                else: ans[i][j] = min(r[p + 1] - r[p] for p in range(len(r) - 1))
        return ans