class Solution:
    def numberOfPairs(self, nums1: List[int], nums2: List[int], k: int) -> int:
        total = 0
        for num in nums1:
            for i in range(len(nums2)):
                if num % (nums2[i] * k) == 0:
                    total += 1
        return total
