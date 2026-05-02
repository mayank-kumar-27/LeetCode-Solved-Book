class Solution:
    def rotatedDigits(self, n: int) -> int:
        c = 0
        for i in range(1, n + 1):
            s = str(i)
            g, b = False, False
            for ch in s:
                if ch in "347":
                    b = True
                    break
                if ch in "2569":
                    g = True
            if not b and g:
                c += 1
        return c
