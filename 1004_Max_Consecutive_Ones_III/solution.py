class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        j = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                k -= 1
            if k < 0:
                if nums[j] == 0:
                    k += 1
                j += 1
        return len(nums) - j