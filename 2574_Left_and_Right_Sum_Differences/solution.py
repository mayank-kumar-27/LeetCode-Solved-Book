class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        t, l, r = sum(nums), 0, []
        for n in nums:
            rs = t - l - n
            r.append(abs(rs - l))
            l += n
        return r