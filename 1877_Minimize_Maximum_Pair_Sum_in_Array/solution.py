class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        n, result = len(nums), 0
        nums.sort()
        for i in range(n // 2):
            s = nums[i] + nums[n - 1 - i]
            if s > result: result = s
        return result
