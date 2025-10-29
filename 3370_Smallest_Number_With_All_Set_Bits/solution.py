class Solution:
    def smallestNumber(self, n: int) -> int:
        power = 2
        while power <= n:
            power *= 2
        return power - 1