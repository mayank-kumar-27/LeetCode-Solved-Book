class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        def get_sum(n):
            divisors = set()

            i = 1
            while i * i <= n:
                if n % i == 0:
                    divisors.add(i)
                    divisors.add(n // i)

                    if len(divisors) > 4: return 0
                i += 1
            return sum(divisors) if len(divisors) == 4 else 0

        result = 0
        for num in nums:
            result += get_sum(num)
        return result
