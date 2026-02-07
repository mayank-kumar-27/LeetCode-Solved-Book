class Solution:
    def minimumDeletions(self, s: str) -> int:
        res, a, b = len(s), 0, 0
        for c in s:
            a += c == "a"
        for c in s:
            a -= c == "a"
            res = min(res, a + b)
            b += c == "b"
        return res