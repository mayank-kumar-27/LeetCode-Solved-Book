class Solution:
    def bitwiseComplement(self, n: int) -> int:
        return n ^ ((1 << max(1, n.bit_length())) - 1)