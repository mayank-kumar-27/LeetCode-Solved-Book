class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        m = float("inf")
        for i in range(len(nums)):
            if nums[i] == target: m = min(m, abs(i - start))
        return m
