class Solution:
    def maxOperations(self, s: str) -> int:
        n = len(s)
        ones = 0
        operations = 0

        for i in range(n):
            if s[i] == "1":
                ones += 1
            elif s[i] == "0" and i > 0 and s[i - 1] == "1":
                operations += ones

        return operations
