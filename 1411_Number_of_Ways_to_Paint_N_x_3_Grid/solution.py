class Solution:
    def numOfWays(self, n: int) -> int:
        MOD = 10**9 + 7
        same = diff = 6
        
        for i in range(1, n):
            same, diff = (2 * same + 2 * diff) % MOD, (2 * same + 3 * diff) % MOD
            
        return (same + diff) % MOD
