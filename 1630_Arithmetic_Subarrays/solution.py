class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        result = []
        for i in range(len(l)):
            subarray = sorted(nums[l[i]:r[i] + 1])

            if len(subarray) < 2:
                result.append(True)
                continue

            diff = subarray[1] - subarray[0]
            is_arithmetic = all(subarray[k] - subarray[k-1] == diff for k in range(1, len(subarray)))
            result.append(is_arithmetic)
            
        return result
