class Solution:
    def concatenatedBinary(self, n: int) -> int:
        M = 10**9 + 7
        result = 0
        for i in range(1, n + 1):
            b = i.bit_length()
            result = (result << b) + i
            if result >= M: result %= M
        return result