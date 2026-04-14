class Solution:
    def romanToInt(self, s: str) -> int:
        r = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
        t = 0
        for a, b in zip(s, s[1:]):
            t += -r[a] if r[a] < r[b] else r[a]
        return t + r[s[-1]]
