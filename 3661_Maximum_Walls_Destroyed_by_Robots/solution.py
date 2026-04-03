class Solution:
    def maxWalls(self, robots: List[int], distance: List[int], walls: List[int]) -> int:
        from bisect import bisect_left, bisect_right
        r = sorted(zip(robots, distance))
        walls.sort()
        n = len(r)
        cW = lambda a, b: bisect_right(walls, b) - bisect_left(walls, a) if a <= b else 0
        dp = [[0, 0] for _ in range(n)]
        dp[0][0] = cW(r[0][0] - r[0][1], r[0][0])
        dp[0][1] = cW(r[0][0], min(r[0][0] + r[0][1], r[1][0] - 1 if n > 1 else 2_000_000_000))
        for i in range(1, n):
            cp, cd, pp, pd = r[i][0], r[i][1], r[i-1][0], r[i-1][1]
            lr = max(pp + 1, cp - cd)
            wl = cW(lr, cp)
            ov = cW(lr, min(cp - 1, pp + pd))
            dp[i][0] = max(dp[i-1][0] + wl, dp[i-1][1] + wl - ov)
            rl = r[i+1][0] - 1 if i < n - 1 else 2_000_000_000
            dp[i][1] = max(dp[i-1]) + cW(cp, min(cp + cd, rl))
        return max(dp[-1])