class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        def is_sorted(nums: List[int]) -> bool:
            for i in range(1, len(nums)):
                if nums[i] < nums[i - 1]:
                    return False
            return True

        ops = 0
        while not is_sorted(nums):
            ops += 1
            min_sum, index = float("inf"), -1
            for i in range(1, len(nums)):
                current_sum = nums[i] + nums[i - 1]
                if current_sum < min_sum:
                    min_sum = current_sum
                    index = i
            nums[index - 1] = min_sum
            nums.pop(index)

        return ops
