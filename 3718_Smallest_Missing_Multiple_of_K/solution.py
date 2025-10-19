# class Solution:
#     def missingMultiple(self, nums: List[int], k: int) -> int:
#         n = k
#         while True:
#             if k not in nums:
#                 return k
#             else:
#                 k += n 

class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        nums_set = set(nums)
        n = k
        while k in nums_set:
            k += n
        return k