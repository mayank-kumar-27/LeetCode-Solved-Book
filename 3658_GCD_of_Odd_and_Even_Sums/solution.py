# Method -> 1
# class Solution:
#     def gcd(a: int, b: int):
#         if b == 0:
#             return a
#         return gcd(b, a % b)

#     def gcdOfOddEvenSums(self, n: int) -> int:
#         even, odd = 0, 0
#         for i in range(n):
#             even += i * 2
#             odd += i * 2 - 1

#         return gcd(odd, even)

# Method -> 2
# class Solution:
#     def gcd(a: int, b: int):
#         if b == 0:
#             return a
#         return gcd(b, a % b)

#     def gcdOfOddEvenSums(self, n: int) -> int:
#         even = n * (n - 1)
#         odd = n * n

#         return gcd(odd, even)

# Method -> 3 (Best Solution)
class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        return n