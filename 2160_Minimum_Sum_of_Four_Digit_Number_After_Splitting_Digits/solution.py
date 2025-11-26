# class Solution:
#     def minimumSum(self, num: int) -> int:
#         nums = []
#         while num != 0:
#             nums.append(num % 10)
#             num //= 10

#         nums.sort()

#         num_1 = nums[0] * 10 + nums[3]
#         num_2 = nums[1] * 10 + nums[2]

#         return num_1 + num_2

class Solution:
    def minimumSum(self, num: int) -> int:
        nums = sorted(str(num))
        return int(nums[0] + nums[3]) + int(nums[1] + nums[2])