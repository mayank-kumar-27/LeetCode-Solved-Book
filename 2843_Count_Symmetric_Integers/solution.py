class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        count = 0
        
        for i in range(low, high + 1):
            num = str(i)
            n = len(num)

            if n % 2 != 0:
                continue

            mid = n // 2
            
            s1 = sum(int(num[j]) for j in range(mid))
            s2 = sum(int(num[k]) for k in range(mid, n))

            if s1 == s2:
                count += 1

        return count