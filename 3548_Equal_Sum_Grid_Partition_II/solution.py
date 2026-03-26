class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        def solve(g):
            n, m = len(g), len(g[0])
            bot, top = 0, 0
            bf = [0] * 100001
            tf = [0] * 100001
            for i in range(n):
                for j in range(m):
                    bot += g[i][j]
                    bf[g[i][j]] += 1
            for i in range(n - 1):
                for j in range(m):
                    bot -= g[i][j]
                    bf[g[i][j]] -= 1
                    top += g[i][j]
                    tf[g[i][j]] += 1
                if top == bot: return True
                dt = top - bot
                if 0 < dt <= 100000:
                    h, w = i + 1, m
                    if h > 1 and w > 1:
                        if tf[dt]: return True
                    elif h > 1 and w == 1:
                        if g[0][0] == dt or g[i][0] == dt: return True
                    elif h == 1 and w > 1:
                        if g[0][0] == dt or g[0][w - 1] == dt: return True
                db = bot - top
                if 0 < db <= 100000:
                    h, w = n - i - 1, m
                    if h > 1 and w > 1:
                        if bf[db]: return True
                    elif h > 1 and w == 1:
                        if g[i + 1][0] == db or g[n - 1][0] == db: return True
                    elif h == 1 and w > 1:
                        if g[n - 1][0] == db or g[n - 1][w - 1] == db: return True
            return False

        if solve(grid): return True
        n, m = len(grid), len(grid[0])
        mat = [[grid[i][j] for i in range(n)] for j in range(m)]
        return solve(mat)