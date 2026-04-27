class Solution:
    def divide(self, x: int, y: int) -> int:
        INT_MAX = 2**31 - 1

        if y == 0:
            return INT_MAX
        if x == y:
            return 1

        p = (x < 0) == (y < 0)

        a = int(x)
        b = int(y)

        if a < 0:
            a = -a
        if b < 0:
            b = -b

        r = 0
        while a >= b:
            q = 0
            while a >= (b << (q + 1)):
                q += 1
            r += (1 << q)
            a -= (b << q)

        if r == (1 << 31) and p:
            return INT_MAX

        return int(r) if p else int(-r)