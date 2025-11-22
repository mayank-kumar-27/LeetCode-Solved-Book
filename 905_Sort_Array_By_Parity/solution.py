# class Solution:
#     def sortArrayByParity(self, nums: List[int]) -> List[int]:
#         even = []
#         odd = []
#         for num in nums:
#             if num % 2 == 0:
#                 even.append(num)
#             else:
#                 odd.append(num)

#         return even + odd

class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        n = len(nums)
        even, odd = 0, n - 1
        result = [0] * n

        for i in range(n):
            if nums[i] % 2 == 0:
                result[even] = nums[i]
                even += 1
            else:
                result[odd] = nums[i]
                odd -= 1

        return result