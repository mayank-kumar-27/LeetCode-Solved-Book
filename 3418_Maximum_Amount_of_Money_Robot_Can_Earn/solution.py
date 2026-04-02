class Solution:
    def maximumAmount(self, coins: List[List[int]]) -> int:
        r, c = len(coins), len(coins[0])
        d = [[[-inf] * 4 for _ in range(c)] for _ in range(r)]
        d[0][0][2] = coins[0][0]
        d[0][0][1] = 0

        for i in range(1, r):
            v = coins[i][0]
            for k in range(3):
                d[i][0][k] = d[i-1][0][k] + v if v >= 0 else max(d[i-1][0][k] + v, d[i-1][0][k+1])

        for j in range(1, c):
            v = coins[0][j]
            for k in range(3):
                d[0][j][k] = d[0][j-1][k] + v if v >= 0 else max(d[0][j-1][k] + v, d[0][j-1][k+1])

        for i in range(1, r):
            for j in range(1, c):
                v = coins[i][j]
                for k in range(3):
                    d[i][j][k] = max(d[i-1][j][k], d[i][j-1][k]) + v if v >= 0 else \
                                  max(d[i-1][j][k] + v, d[i][j-1][k] + v, d[i-1][j][k+1], d[i][j-1][k+1])

        return max(d[-1][-1])