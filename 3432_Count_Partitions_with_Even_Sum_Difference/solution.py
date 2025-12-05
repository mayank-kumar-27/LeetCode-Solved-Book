class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        total_sum, left_sum, count = sum(nums), 0, 0
        for i in range(len(nums) - 1):
            left_sum += nums[i]
            right_sum = total_sum - left_sum
            if (left_sum - right_sum) % 2 == 0: count += 1
            
        return count