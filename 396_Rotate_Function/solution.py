class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        t, n, s = 0, len(nums), sum(nums)
        for i, num in enumerate(nums):
            t += i * num
        r = t
        for i in range(n - 1, 0, -1):
            t += s - n * nums[i]
            r = max(r, t)
        return r
