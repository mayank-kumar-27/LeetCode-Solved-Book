class Solution:
    def mergeAdjacent(self, nums: List[int]) -> List[int]:
        s = []
        for x in nums:
            v = x
            while s and s[-1] == v:
                v += s.pop()
            s.append(v)
        return s