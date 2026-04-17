class Solution:
    def longestCommonPrefix(self, a: List[str]) -> str:
        a.sort()
        s, t = a[0], a[-1]
        r = ""
        for i in range(min(len(s), len(t))):
            if s[i] != t[i]: break
            r += s[i]
        return r
