# class Solution:
#     def alternatingSum(self, nums: List[int]) -> int:
#         result = 0
#         for i in range(len(nums)):
#             if i % 2 == 0:
#                 result += nums[i]
#             else:
#                 result -= nums[i]
#         return result

class Solution:
    def alternatingSum(self, nums: List[int]) -> int:
        return sum(nums[::2]) - sum(nums[1::2])