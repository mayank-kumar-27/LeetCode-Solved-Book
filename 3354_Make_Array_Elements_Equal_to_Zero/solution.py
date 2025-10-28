class Solution:
    def countValidSelections(self, nums: List[int]) -> int:
        total = sum(nums)
        left_sum, count = 0, 0
        
        for num in nums:
            if num == 0:
                right_sum = total - left_sum
                diff = abs(left_sum - right_sum)
                count += 2 if diff == 0 else (1 if diff == 1 else 0)
            left_sum += num
        
        return count