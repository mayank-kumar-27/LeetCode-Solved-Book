class Solution:
    def numberOfSteps(self, num: int) -> int:
        count = 0
        while num:
            num = num // 2 if num % 2 == 0 else num - 1
            count += 1
        return count
