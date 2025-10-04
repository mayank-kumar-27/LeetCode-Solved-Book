class Solution:
    def reverse(self, x: int) -> int:
        sign = -1 if x < 0 else 1
        reversed_num = int(str(abs(x))[::-1]) * sign

        if abs(reversed_num) > 2**31 - 1:
            return 0

        return reversed_num
