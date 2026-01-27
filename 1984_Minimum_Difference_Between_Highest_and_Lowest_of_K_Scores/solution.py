class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        n = len(nums)
        nums.sort()
        result = nums[k - 1] - nums[0]
        for i in range(n - k + 1):
            result = min(result, nums[i + k - 1] - nums[i])
        return result