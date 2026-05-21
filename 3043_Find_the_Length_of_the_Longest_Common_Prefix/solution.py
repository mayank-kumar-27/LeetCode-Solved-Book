class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        ap = set()
        for v in arr1:
            while v not in ap and v > 0:
                ap.add(v)
                v //= 10
        lp = 0
        for v in arr2:
            while v not in ap and v > 0:
                v //= 10
            if v > 0:
                lp = max(lp, len(str(v)))
        return lp
