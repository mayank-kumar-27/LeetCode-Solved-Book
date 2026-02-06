class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        nums.sort()
        max_len, low = 1, 0
        for high in range(len(nums)):
            while low < high and nums[high] > nums[low] * k:
                low += 1
            max_len = max(max_len, high - low + 1)
        return len(nums) - max_len