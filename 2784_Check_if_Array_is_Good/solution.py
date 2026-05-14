class Solution:
    def isGood(self, nums: List[int]) -> bool:
        n = len(nums)
        c = [0] * n
        for a in nums:
            if a >= n:
                return False
            if a < n - 1 and c[a] > 0:
                return False
            if a == n - 1 and c[a] > 1:
                return False
            c[a] += 1
        return True
