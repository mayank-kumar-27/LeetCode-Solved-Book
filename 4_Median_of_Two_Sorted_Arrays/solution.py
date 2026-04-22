class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        merged_list = sorted(nums1 + nums2)
        n = len(merged_list)
        if n % 2 == 0:
            return (merged_list[n // 2 - 1] + merged_list[n // 2]) / 2
        else:
            return merged_list[n // 2]
