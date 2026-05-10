class Solution:
    def maximumJumps(self, n: List[int], t: int) -> int:
        @cache
        def dfs(i: int):
            if i == len(n) - 1:
                return 0
            r = -inf
            for j in range(i + 1, len(n)):
                if abs(n[i] - n[j]) <= t:
                    r = max(r, dfs(j) + 1)
            return r

        a = dfs(0)
        return -1 if a < 0 else a
