class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        c, count = 0, 0
        for num in nums:
            if count == 0: c = num
            count += 1 if num == c else -1
        return c