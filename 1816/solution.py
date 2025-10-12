# class Solution:
#     def truncateSentence(self, s: str, k: int) -> str:
#         spaceCount, index = 0, 0
#         while index < len(s) and spaceCount < k:
#             if s[index] == " ":
#                 spaceCount += 1
#             index += 1

#         return s[: index - 1] if spaceCount == k else s

class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        return ' '.join(s.split()[:k])