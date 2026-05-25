class Solution:
    def canReach(self, s: str, mj: int, maxJump: int) -> bool:
        n = len(s)
        f, p = [0] * n, [0] * n
        f[0] = 1
        for i in range(mj):
            p[i] = 1
        for i in range(mj, n):
            l, r = i - maxJump, i - mj
            if s[i] == "0":
                total = p[r] - (0 if l <= 0 else p[l - 1])
                f[i] = int(total != 0)
            p[i] = p[i - 1] + f[i]

        return bool(f[n - 1])
