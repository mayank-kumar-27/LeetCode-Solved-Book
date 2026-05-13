class Solution:
    def minMoves(self, nums: List[int], limit: int) -> int:
        n = len(nums)
        d = [0] * (2 * limit + 2)
        for i in range(n // 2):
            a = min(nums[i], nums[n - 1 - i])
            b = max(nums[i], nums[n - 1 - i])
            d[2] += 2
            d[a + 1] -= 1
            d[a + b] -= 1
            d[a + b + 1] += 1
            d[b + limit + 1] += 1
        m = n
        cp = 0
        for c in range(2, 2 * limit + 1):
            cp += d[c]
            if cp < m:
                m = cp
        return m