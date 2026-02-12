class Solution:
    def longestBalanced(self, s: str) -> int:
        n, result = len(s), 0
        for i in range(n):
            count = {}
            for j in range(i, n):
                count[s[j]] = count.get(s[j], 0) + 1
                freq = list(count.values())
                if len(set(freq)) == 1:
                    result = max(result, j - i + 1)

        return result