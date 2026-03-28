class Solution:
    def findTheString(self, lcp: List[List[int]]) -> str:
        n = len(lcp)
        s = ["X"] * n
        id_ = -1

        for i in range(n):
            if lcp[i][i] != n - i: return ""
            if s[i] >= "a": continue
            id_ += 1
            if id_ >= 26: return ""
            for j in range(i, n):
                if lcp[i][j]: s[j] = chr(ord("a") + id_)

        for i in range(n):
            for j in range(i):
                x = lcp[i][j]
                if x != lcp[j][i] or x + i > n: return ""
                y = lcp[i + 1][j + 1] if i < n - 1 else 0
                y = y + 1 if s[i] == s[j] else 0
                if x != y: return ""

        return "".join(s)
