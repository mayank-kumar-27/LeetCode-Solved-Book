class Solution:
    def check(self, nums: List[int]) -> bool:
        n = len(nums)
        for i in range(n):
            f = []
            for j in range(i, n):
                f.append(nums[j])
            for j in range(i):
                f.append(nums[j])
            s = True
            for j in range(n - 1):
                if f[j] > f[j + 1]:
                    s = False
                    break
            if s:
                return True
        return False
