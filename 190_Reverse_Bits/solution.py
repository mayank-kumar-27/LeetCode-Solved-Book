class Solution:
    def reverseBits(self, n: int) -> int:
        b = format(n, "032b")
        rev = b[::-1]
        return int(rev, 2)