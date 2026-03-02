class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        n = len(grid)
        z, s = [], 0
        for r in grid:
            c = 0
            for j in range(n - 1, -1, -1):
                if r[j] == 0: c += 1
                else: break
            z.append(c)

        for i in range(n):
            r, j = n - i - 1, i
            while j < n and z[j] < r: j += 1

            if j == n: return -1
            while j > i:
                z[j], z[j - 1] = z[j - 1], z[j]
                j -= 1; s += 1

        return s