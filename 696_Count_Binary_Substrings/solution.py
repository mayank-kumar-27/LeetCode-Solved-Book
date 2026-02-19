class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        result, prev, curr = 0, 0, 1
        for i in range(1, len(s)):
            if s[i] == s[i - 1]: curr += 1
            else: 
                prev = curr
                curr = 1
            if curr <= prev: result += 1
        return result