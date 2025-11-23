# class Solution:
#     def sumAndMultiply(self, n: int) -> int:
#         num = 0
#         sum_of_digits = 0

#         while n != 0:
#             digit = n % 10
#             if digit != 0:
#                 num = num * 10 + digit
#                 sum_of_digits += digit
#             n //= 10

#         return int(str(num)[::-1]) * sum_of_digits

class Solution:
    def sumAndMultiply(self, n: int) -> int:
        num, sum_of_digits, multiplier = 0, 0, 1

        while n != 0:
            digit = n % 10
            if digit != 0:
                num = digit * multiplier + num
                multiplier *= 10
                sum_of_digits += digit
            n //= 10

        return num * sum_of_digits