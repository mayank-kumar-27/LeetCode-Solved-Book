# class Solution:
#     def findKthLargest(self, nums: List[int], k: int) -> int:
#         sorted_nums = sorted(nums)
#         n = len(nums)
#         return sorted_nums[n - k]

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        return sorted(nums)[-k]