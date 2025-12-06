# class Solution:
#     def moveZeroes(self, nums: List[int]) -> None:
#         """
#         Do not return anything, modify nums in-place instead.
#         """
#         index = 0
#         for i in nums:
#             if i != 0:
#                 nums[index] = i
#                 index += 1
#         for i in range(index, len(nums)):
#             nums[i] = 0

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        index = 0
        for i in nums:
            if i != 0:
                nums[index] = i
                index += 1
        nums[index:] = [0] * (len(nums) - index)