class Solution:
    def reverseSubmatrix(self, grid: List[List[int]], x: int, y: int, k: int) -> List[List[int]]:
        for i in range(k >> 1):
            r1 = grid[x + i]
            r2 = grid[x + k - 1 - i]
            for j in range(k):
                r1[y + j], r2[y + j] = r2[y + j], r1[y + j]
        return grid