class Solution:
    def scoreOfString(self, s: str) -> int:
        n = len(s)
        sum_of_ASCII = 0
        for i in range(n - 1):
            sum_of_ASCII += abs(ord(s[i]) - ord(s[i + 1]))

        return sum_of_ASCII