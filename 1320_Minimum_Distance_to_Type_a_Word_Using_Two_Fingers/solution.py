class Solution:
    def minimumDistance(self, word: str) -> int:
        dist = lambda x, y: (
            0 if 26 in (x, y) else abs(x // 6 - y // 6) + abs(x % 6 - y % 6)
        )
        INF, n = 1 << 30, len(word)
        dp = [[INF] * 27 for _ in range(n)]
        dp[0][26] = 0
        p = ord(word[0]) - 65
        for i, c in enumerate(word[1:], 1):
            x = ord(c) - 65
            for j in range(27):
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + dist(p, x))
                dp[i][p] = min(dp[i][p], dp[i - 1][j] + dist(j, x))
            p = x
        return min(dp[-1])
