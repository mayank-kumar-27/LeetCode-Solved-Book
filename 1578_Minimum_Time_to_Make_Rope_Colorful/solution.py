class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        result = 0
        i = 0

        while i < len(neededTime) - 1:
            if colors[i] == colors[i + 1]:
                j = i
                max_time = neededTime[i]
                sum_time = neededTime[i]

                while j + 1 < len(neededTime) and colors[j] == colors[j + 1]:
                    j += 1
                    sum_time += neededTime[j]
                    if neededTime[j] > max_time:
                        max_time = neededTime[j]

                result += sum_time - max_time
                i = j

            i += 1

        return result
