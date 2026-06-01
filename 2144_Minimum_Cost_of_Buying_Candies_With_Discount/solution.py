class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        cost.sort(key=lambda x: -x)
        r = 0
        n = len(cost)
        for i in range(n):
            if i % 3 != 2:
                r += cost[i]
        return r
