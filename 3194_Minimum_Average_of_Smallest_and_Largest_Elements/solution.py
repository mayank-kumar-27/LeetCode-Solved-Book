class Solution:
    def minimumAverage(self, nums: List[int]) -> float:
        averages, n = [], len(nums)
        nums.sort()
        for i in range(n // 2):
            averages.append((nums[i] + nums[n - i - 1]) / 2)
        return min(averages)