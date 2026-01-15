class Solution:
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        n, count = len(nums), 0
        for i in range(n):
            for j in range(i, n):
                if nums[j] - nums[i] == diff:
                    for k in range(j, n):
                        if nums[k] - nums[j] == diff:
                            count += 1
        return count
