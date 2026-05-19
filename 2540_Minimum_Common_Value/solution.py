class Solution:
    def getCommon(self, arr1: List[int], arr2: List[int]) -> int:
        s = set(arr2)
        for i in arr1:
            if i in s:
                return i
        return -1
