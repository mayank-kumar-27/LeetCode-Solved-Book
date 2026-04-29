class Solution:
    def maximumScore(self, g: List[List[int]]) -> int:
        n = len(g[0])
        if n == 1:
            return 0
        d = [[[0] * (n + 1) for _ in range(n + 1)] for _ in range(n)]
        p = [[0] * (n + 1) for _ in range(n + 1)]
        s = [[0] * (n + 1) for _ in range(n + 1)]
        c = [[0] * (n + 1) for _ in range(n)]
        for i in range(n):
            for j in range(1, n + 1):
                c[i][j] = c[i][j - 1] + g[j - 1][i]
        for i in range(1, n):
            for x in range(n + 1):
                for y in range(n + 1):
                    if x <= y:
                        e = c[i][y] - c[i][x]
                        d[i][x][y] = max(d[i][x][y],s[y][0] + e)
                    else:
                        e = c[i - 1][x] - c[i - 1][y]
                        d[i][x][y] = max(d[i][x][y],s[y][x],p[y][x] + e)
            for x in range(n + 1):
                p[x][0] = d[i][x][0]
                for y in range(1, n + 1):
                    q = c[i][y] - c[i][x] if y > x else 0
                    p[x][y] = max(p[x][y - 1],d[i][x][y] - q)
                s[x][n] = d[i][x][n]
                for y in range(n - 1, -1, -1):
                    s[x][y] = max(s[x][y + 1],d[i][x][y])
        a = 0
        for k in range(n + 1):
            a = max(a, d[n - 1][n][k], d[n - 1][0][k])
        return a
