import math
class Solution:
    def minNumberOfSeconds(self, mountainHeight: int, workerTimes: List[int]) -> int:
        lo, hi = 1, 10**16
        while lo < hi:
            m = (lo + hi) >> 1
            s = sum(int(math.sqrt(m / t * 2 + 0.25) - 0.5) for t in workerTimes)
            if s >= mountainHeight: hi = m
            else: lo = m + 1
        return lo