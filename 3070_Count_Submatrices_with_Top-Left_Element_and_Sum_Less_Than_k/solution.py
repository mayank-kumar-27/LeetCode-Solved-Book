class Solution:
    def countSubmatrices(self, grid: List[List[int]], k: int) -> int:
        m, n, r = len(grid), len(grid[0]), 0
        for i in range(m):
            for j in range(n):
                u = grid[i - 1][j] if i > 0 else 0
                l = grid[i][j - 1] if j > 0 else 0
                d = grid[i - 1][j - 1] if i > 0 and j > 0 else 0

                grid[i][j] = grid[i][j] + u + l - d
                if grid[i][j] <= k: r += 1
                else:
                    if j == 0: return r
                    break
        return r