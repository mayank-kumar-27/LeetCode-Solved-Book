class Solution:
    def rotateGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        nl = min(m // 2, n // 2)
        for l in range(nl):
            r = []
            c = []
            val = []
            for i in range(l, m - l - 1):
                r.append(i)
                c.append(l)
                val.append(grid[i][l])
            for j in range(l, n - l - 1):
                r.append(m - l - 1)
                c.append(j)
                val.append(grid[m - l - 1][j])
            for i in range(m - l - 1, l, -1):
                r.append(i)
                c.append(n - l - 1)
                val.append(grid[i][n - l - 1])
            for j in range(n - l - 1, l, -1):
                r.append(l)
                c.append(j)
                val.append(grid[l][j])
            total = len(val)
            kk = k % total

            for i in range(total):
                idx = (i + total - kk) % total
                grid[r[i]][c[i]] = val[idx]
        return grid
