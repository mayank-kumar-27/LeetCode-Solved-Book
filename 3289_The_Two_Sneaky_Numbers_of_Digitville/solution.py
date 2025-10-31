# class Solution:
#     def getSneakyNumbers(self, nums: List[int]) -> List[int]:
#         freq = {}
#         result = []
#         for num in nums:
#             freq[num] = freq.get(num, 0) + 1
#         for key, value in freq.items():
#             if value == 2:
#                 result.append(key)
#         return result

class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        seen, result = set(), []
        for num in nums:
            if num in seen:
                result.append(num)
            else:
                seen.add(num)
        return result