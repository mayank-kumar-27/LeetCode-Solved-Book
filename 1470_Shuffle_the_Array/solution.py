# class Solution:
#     def shuffle(self, nums: List[int], n: int) -> List[int]:
#         i, j = 0, 0
#         result = []

#         while i < len(nums):
#             result.append(nums[j])
#             result.append(nums[n])
#             i += 2
#             j += 1
#             n += 1

#         return result

class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        result = []
        for i in range(n):
            result.append(nums[i])
            result.append(nums[n + i])
        return result