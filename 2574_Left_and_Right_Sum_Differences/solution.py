class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        total = sum(nums)
        left_sum = 0
        result = []
        
        for num in nums:
            right_sum = total - left_sum - num
            result.append(abs(left_sum - right_sum))
            left_sum += num
        
        return result