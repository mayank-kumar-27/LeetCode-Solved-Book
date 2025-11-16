class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        max_count, count = 0, 0
        for num in nums:
            count = count + 1 if num == 1 else 0
            max_count = max(max_count, count)
        return max_count
