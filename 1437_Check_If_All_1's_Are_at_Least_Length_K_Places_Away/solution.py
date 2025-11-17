class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        index = []
        for i in range(len(nums)):
            if nums[i] == 1:
                index.append(i)

        for i in range(len(index) - 1):
            if index[i + 1] - index[i] <= k:
                return False

        return True