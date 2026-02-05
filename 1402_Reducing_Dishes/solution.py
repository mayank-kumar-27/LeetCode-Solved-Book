class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        satisfaction.sort()
        res = s = 0
        for x in reversed(satisfaction):
            s += x
            if s <= 0: break
            res += s
        return res