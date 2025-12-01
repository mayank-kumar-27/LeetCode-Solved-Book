class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        ones, n = s.count("1"), len(s)
        return "1" * (ones - 1) + "0" * (n - ones) + "1"