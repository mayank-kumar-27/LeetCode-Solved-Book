class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        s = dict()

        def dfs(p):
            if p in s: return
            s[p] = 1
            i = p - 1
            while i >= 0 and p - i <= d and arr[p] > arr[i]:
                dfs(i)
                s[p] = max(s[p], s[i] + 1)
                i -= 1
            i = p + 1
            while i < len(arr) and i - p <= d and arr[p] > arr[i]:
                dfs(i)
                s[p] = max(s[p], s[i] + 1)
                i += 1

        for i in range(len(arr)):
            dfs(i)
        return max(s.values())
