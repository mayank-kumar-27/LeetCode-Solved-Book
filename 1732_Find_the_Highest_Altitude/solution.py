# class Solution:
#     def largestAltitude(self, gain: List[int]) -> int:
#         n = len(gain)
#         result = [0] * (n + 1)

#         for i in range(n):
#             result[i + 1] = result[i] + gain[i]

#         return max(result)

class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        temp, maxx = 0, 0
        for i in range(len(gain)):
            temp += gain[i]
            if temp > maxx:
                maxx = temp
        return maxx