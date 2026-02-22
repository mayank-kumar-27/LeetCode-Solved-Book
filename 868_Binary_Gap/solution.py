class Solution:
    def binaryGap(self, n: int) -> int:
        if (n & (n - 1)) == 0:
            return 0
        n //= n & -n
        max_gap, gap = 0, 0

        while n:
            if n & 1:
                max_gap = max(max_gap, gap)
                gap = 0
            else:
                gap += 1
            n >>= 1

        return max_gap + 1