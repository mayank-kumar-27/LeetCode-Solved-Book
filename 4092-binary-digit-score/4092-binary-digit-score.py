class Solution:
    def calculateScore(self, a: int, b: int) -> int:
        s, t = bin(a), bin(b)
        u, v = s.count("1"), t.count("1")
        if u >= v: return u * v
        else: return v // u
