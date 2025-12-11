class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        m = max(nums)
        nums.remove(m)
        n = max(nums)
        return (m - 1) * (n - 1)
