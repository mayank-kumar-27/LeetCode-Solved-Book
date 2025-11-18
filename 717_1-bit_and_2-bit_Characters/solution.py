class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        i = 0
        n = len(bits)

        while i < n:
            if i == n - 1:
                return True
            if bits[i] == 1:
                i += 2
            else:
                i += 1

        return False
