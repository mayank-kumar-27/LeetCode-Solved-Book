class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        h, m = (hour % 12) * 30.0 + minutes * 0.5, minutes * 6.0
        d = abs(h - m)
        return min(d, (360.0 - d))
