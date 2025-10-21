class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0:
            return 0

        low, high = 1, x

        while low <= high:
            mid = low + (high - low) // 2
            sqrt = mid * mid

            if sqrt == x:
                return mid
            elif sqrt < x:
                low = mid + 1
            else:
                high = mid - 1

        return high
