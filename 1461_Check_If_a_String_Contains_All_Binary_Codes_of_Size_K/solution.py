class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        if len(s) < k + 2**k - 1: return False
        
        seen = set()
        for i in range(len(s) - k + 1): seen.add(s[i : i + k])
        return len(seen) == 2**k