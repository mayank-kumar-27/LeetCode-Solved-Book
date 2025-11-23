class Solution:
    def sumAndMultiply(self, n: int) -> int:
        num = 0
        sum_of_digits = 0

        while n != 0:
            digit = n % 10
            if digit != 0:
                num = num * 10 + digit
                sum_of_digits += digit
            n //= 10

        return int(str(num)[::-1]) * sum_of_digits