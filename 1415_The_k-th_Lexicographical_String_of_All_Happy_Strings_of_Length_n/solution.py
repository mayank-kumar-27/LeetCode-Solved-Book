class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        t = 3 * (2 ** (n - 1))
        if k > t: return ""
        k -= 1
        r = []
        p = ""

        for i in range(n):
            b = 2 ** (n - i - 1)
            c = [x for x in "abc" if x != p]

            j = k // b
            r.append(c[j])

            p = c[j]
            k %= b

        return "".join(r)