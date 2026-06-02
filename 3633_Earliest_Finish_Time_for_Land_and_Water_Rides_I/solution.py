class Solution:
    def earliestFinishTime(self, lStartTime: List[int], lDuration: List[int], wStartTime: List[int], wDuration: List[int]) -> int:
        n = len(lStartTime)
        m = len(wStartTime)
        r = inf
        for i in range(n):
            for j in range(m):
                l = lStartTime[i] + lDuration[i]
                lw = max(l, wStartTime[j]) + wDuration[j]
                r = min(r, lw)

                w = wStartTime[j] + wDuration[j]
                wl = max(w, lStartTime[i]) + lDuration[i]
                r = min(r, wl)
        return r
