class Solution:
    def sum_of_digit(self, num):
        total = 0
        while num > 0:
            digit = num % 10
            total += digit**2
            num //= 10
        return total

    def isHappy(self, n: int) -> bool:
        seen = set()
        while n != 1 and n not in seen:
            seen.add(n)
            n = self.sum_of_digit(n)
        return n == 1
