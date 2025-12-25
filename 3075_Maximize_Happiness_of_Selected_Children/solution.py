class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness.sort(reverse=True)
        max_happy = 0

        for i in range(k):
            max_happy += max(0, happiness[i] - i)
        return max_happy
