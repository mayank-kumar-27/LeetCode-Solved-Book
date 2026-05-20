class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        pca = [0] * n
        for i in range(n):
            c = 0
            for a_index in range(i + 1):
                for b_index in range(i + 1):
                    if A[a_index] == B[b_index]:
                        c += 1
                        break
            pca[i] = c
        return pca
