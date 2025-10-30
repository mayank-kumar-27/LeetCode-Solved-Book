# class Solution:
#     def minNumberOperations(self, target: List[int]) -> int:
#         operation, prev = 0, 0
#         for num in target:
#             if num > prev:
#                 operation += num - prev
#             prev = num
#         return operation

class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        operation = target[0]
        for i in range(len(target) - 1):
            if target[i + 1] > target[i]:
                operation += target[i + 1] - target[i]
        return operation