class Solution:
    def maxIceCream(self, c: List[int], k: int) -> int:
        m = max(c)
        f = [0] * (m + 1)
        for x in c: f[x] += 1
        r = 0
        for i in range(1, m + 1):
            if k < i: break
            x = min(f[i], k // i)
            r += x
            k -= x * i
        return r