class Solution:
    def removeZeros(self, n: int) -> int:
        digits = []
        while n != 0:
            if n % 10 != 0:
                digits.append(n % 10)
            n //= 10

        result = 0
        for digit in reversed(digits):
            result = result * 10 + digit
        return result
