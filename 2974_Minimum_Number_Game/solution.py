# class Solution:
#     def numberGame(self, nums: List[int]) -> List[int]:
#         arr = []
#         for i in range(len(nums)//2):
#             minimum_Alice = min(nums)
#             nums.remove(minimum_Alice)
#             minimum_Bob = min(nums)
#             nums.remove(minimum_Bob)
#             arr.append(minimum_Bob)
#             arr.append(minimum_Alice)
#         return arr

class Solution:
    def numberGame(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = []
        nums.sort()

        for i in range(0, n, 2):
            result.append(nums[i + 1])
            result.append(nums[i])

        return result