class Solution:
    def numberOfSubmatrices(self, g: List[List[str]]) -> int:
        r, c = len(g), len(g[0])
        x = [0] * c
        y = [0] * c
        ans = 0
        for i in range(r):
            a = b = 0
            for j in range(c):
                a += g[i][j] == "X"
                b += g[i][j] == "Y"
                x[j] += a
                y[j] += b
                ans += x[j] > 0 and x[j] == y[j]
        return ans