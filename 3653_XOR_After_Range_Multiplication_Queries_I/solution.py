class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        m = 10**9 + 7
        for q in queries:
            l, r, k, v = q
            i = l
            while i <= r:
                nums[i] = (nums[i] * v) % m
                i += k
        x = 0
        for n in nums: x ^= n
        return x
