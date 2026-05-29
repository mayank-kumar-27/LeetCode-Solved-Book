class Solution:
    def minElement(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            s = 0
            while nums[i] > 0:
                s += nums[i] % 10
                nums[i] //= 10
            nums[i] = s
        return min(nums)
