class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        r = []
        for x in nums:
            t = []
            while x > 0:
                t.append(x % 10)
                x //= 10
            r.extend(t[::-1])
        return r
