import string

class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        l, f = {}, {}
        for i, c in enumerate(word):
            if c.islower():
                l[c] = i
            else:
                if c not in f:
                    f[c] = i
        r = 0
        for c in string.ascii_lowercase:
            if c in l and c.upper() in f and l[c] < f[c.upper()]:
                r += 1
        return r
