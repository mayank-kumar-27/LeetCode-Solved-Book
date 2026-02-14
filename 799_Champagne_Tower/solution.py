class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        t = [[0.0] * 102 for _ in range(102)]
        t[0][0] = float(poured)

        for i in range(query_row + 1):
            for j in range(i + 1):
                r = (t[i][j] - 1.0) / 2.0
                if r > 0:
                    t[i + 1][j] += r
                    t[i + 1][j + 1] += r
                    
        return min(1.0, t[query_row][query_glass])