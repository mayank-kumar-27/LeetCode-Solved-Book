class Solution:
    def smallestNumber(self, pattern: str) -> str:
        n = len(pattern)
        result = list(range(1, n + 2))

        i = 0
        while i < n:
            if pattern[i] == "D":
                start = i
                while i < n and pattern[i] == "D":
                    i += 1
                end = i
                result[start : end + 1] = reversed(result[start : end + 1])
            else:
                i += 1

        return "".join(str(x) for x in result)
