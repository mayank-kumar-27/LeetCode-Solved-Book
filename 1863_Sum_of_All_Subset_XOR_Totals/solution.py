class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        or_result = 0
        for num in nums:
            or_result |= num
        return or_result << (len(nums) - 1)