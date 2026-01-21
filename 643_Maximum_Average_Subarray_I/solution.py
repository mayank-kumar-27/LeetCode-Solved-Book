class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        window_sum = sum(nums[:k])
        maximum_sum = window_sum

        for i in range(k, len(nums)):
            window_sum = window_sum - nums[i - k] + nums[i]
            maximum_sum = max(maximum_sum, window_sum)
        return maximum_sum / k
