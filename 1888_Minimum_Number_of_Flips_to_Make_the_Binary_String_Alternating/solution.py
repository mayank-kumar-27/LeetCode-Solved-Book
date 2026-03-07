class Solution:
    def minFlips(self, s: str) -> int:
        n = len(s)
        s += s
        alt1 = alt2 = res = 0
        res = float("inf")
        for i, c in enumerate(s):
            alt1 += c != str(i % 2)
            alt2 += c != str((i + 1) % 2)
            if i >= n:
                alt1 -= s[i - n] != str((i - n) % 2)
                alt2 -= s[i - n] != str((i - n + 1) % 2)
            if i >= n - 1:
                res = min(res, alt1, alt2)
        return res