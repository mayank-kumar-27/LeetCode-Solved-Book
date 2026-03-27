class Solution:
    def areSimilar(self, mat: List[List[int]], k: int) -> bool:
        n, k = len(mat[0]), k % len(mat[0])
        return all(mat[i][j] == mat[i][(j + k) % n if i % 2 == 0 else (j - k) % n] for i in range(len(mat)) for j in range(n))