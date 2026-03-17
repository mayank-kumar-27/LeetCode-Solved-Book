class Solution:
    def largestSubmatrix(self, matrix: list[list[int]]) -> int:
        m, n, a = len(matrix), len(matrix[0]), 0
        h = [0] * n

        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 1: h[j] += 1
                else: h[j] = 0
            s = sorted(h, reverse=True)
            for j in range(n):
                if s[j] == 0: break
                a = max(a, s[j] * (j + 1))

        return a