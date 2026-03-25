class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        t = sum(sum(r) for r in grid)

        if t % 2: return False
        a = t // 2

        s = 0
        for i in range(m - 1):
            s += sum(grid[i])
            if s == a: return True
        s = 0
        for j in range(n - 1):
            for i in range(m): s += grid[i][j]
            if s == a: return True
            
        return False
