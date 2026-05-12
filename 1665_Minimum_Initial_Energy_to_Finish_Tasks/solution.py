class Solution:
    def minimumEffort(self, ts: List[List[int]]) -> int:
        ts.sort(key=lambda x: x[1] - x[0])
        a = 0
        for t in ts:
            a = max(a + t[0], t[1])
        return a
