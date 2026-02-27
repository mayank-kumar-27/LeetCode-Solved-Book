class Solution:
    def minOperations(self, s: str, k: int) -> int:
        n = len(s)
        z = sum(~ord(c) & 1 for c in s)

        if z == 0: return 0
        if n == k: return 1 if z == n else -1

        b = n - k
        o = max(math.ceil(z / k), math.ceil((n - z) / b))
        o += ~o & 1
        e = max(math.ceil(z / k), math.ceil(z / b))
        e += e & 1

        r = min(o if (k & 1) == (z & 1) else float("inf"), e if (~z & 1) == 1 else float("inf"),)

        return -1 if r == float("inf") else r