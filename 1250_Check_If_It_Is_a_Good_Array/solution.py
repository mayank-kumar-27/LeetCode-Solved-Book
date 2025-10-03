class Solution:
    def isGoodArray(self, nums: List[int]) -> bool:
        def gcd(a: int, b: int) -> int:
            if b == 0:
                return a
            else:
                return gcd(b, a % b)

        GCD = nums[0]
        for i in range(len(nums) - 1):
            GCD = gcd(GCD, nums[i + 1])

        return GCD == 1
