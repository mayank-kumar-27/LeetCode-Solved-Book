class Solution:
    def closestTarget(self, ws: List[str], target: str, si: int) -> int:
        a = n = len(ws)
        for i, w in enumerate(ws):
            if w == target: a = min(a, abs(i - si), n - abs(i - si))
        return a if a < n else -1
