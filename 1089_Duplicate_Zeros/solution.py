class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        n = len(arr)
        i = 0
        while i < n:
            if arr[i] == 0 and i + 1 < n:
                for j in range(n - 1, i, -1):
                    arr[j] = arr[j - 1]
                arr[i + 1] = 0
                i += 2
            else:
                i += 1
