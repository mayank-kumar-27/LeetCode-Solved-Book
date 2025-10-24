class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        index = 0

        for i in range(len(nums) - 1):
            if nums[i] == nums[i + 1]:
                continue
            else:
                nums[index] = nums[i]
                index += 1

        nums[index] = nums[-1]
        return index + 1