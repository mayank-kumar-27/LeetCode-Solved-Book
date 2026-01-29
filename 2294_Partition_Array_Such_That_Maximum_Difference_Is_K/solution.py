class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        m, count = nums[0], 1
        for i in range(len(nums)):
            if nums[i] - m > k:
                count+=1
                m = nums[i]
        return count