class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [0] * n
        result[0] = nums[0]

        for i in range(1, n):
            result[i] = result[i - 1] + nums[i]

        return result
