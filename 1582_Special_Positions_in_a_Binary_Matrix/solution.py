class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        return sum(sum(mat[i]) == 1 and sum(mat[r][j] for r in range(len(mat))) == 1 for i in range(len(mat)) for j in range(len(mat[0])) if mat[i][j])