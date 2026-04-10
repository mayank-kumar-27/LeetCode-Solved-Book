class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        n, L, r = len(nums), [0] * len(nums), 200
        for i in range(n):
            v, p = nums[i] - 1, i + 1
            pk = L[v]
            o, c = pk & 255, pk >> 8
            L[v] = c | (p << 8)
            if o: r = min(r, (p - o) << 1)
        return -(r == 200) | r
