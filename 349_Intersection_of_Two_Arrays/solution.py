# class Solution:
#     def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
#         nums1_set, nums2_set = set(nums1), set(nums2)
#         result = []
#         for num in nums1_set:
#             if num in nums2_set:
#                 result.append(num)
#         return result

class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return list(set(nums1) & set(nums2))