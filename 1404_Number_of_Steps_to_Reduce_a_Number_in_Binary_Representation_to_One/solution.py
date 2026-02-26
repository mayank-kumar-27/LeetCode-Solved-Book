class Solution:
    def numSteps(self, s: str) -> int:
        st, c = 0, 0
        for i in range(len(s) - 1, 0, -1):
            b = ord(s[i]) & 1
            st += 1 + (b ^ c)
            c |= b
        return st + c