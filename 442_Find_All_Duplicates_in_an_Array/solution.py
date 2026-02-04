class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        freq = {}
        for num in nums:
            freq[num] = freq.get(num, 0) + 1

        result = []
        for key, value in freq.items():
            if value > 1:
                result.append(key)
        
        return result