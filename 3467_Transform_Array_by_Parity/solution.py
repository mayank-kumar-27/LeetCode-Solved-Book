class Solution:
    def transformArray(self, nums: List[int]) -> List[int]:
        transformed_list = []
        for num in nums:
            if num % 2 == 0:
                transformed_list.append(0)
            else:
                transformed_list.append(1)
        transformed_list.sort()
        return transformed_list
