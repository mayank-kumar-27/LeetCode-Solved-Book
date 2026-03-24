class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        MOD = 12345
        rows = len(grid)
        cols = len(grid[0])
        prod_matrix = [[1] * cols for _ in range(rows)]
        prefix = 1
        for i in range(rows):
            for j in range(cols):
                prod_matrix[i][j] = prefix
                prefix = (prefix * grid[i][j]) % MOD
        suffix = 1
        for i in range(rows - 1, -1, -1):
            for j in range(cols - 1, -1, -1):
                prod_matrix[i][j] = (prod_matrix[i][j] * suffix) % MOD
                suffix = (suffix * grid[i][j]) % MOD
        return prod_matrix