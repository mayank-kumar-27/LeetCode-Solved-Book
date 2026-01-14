class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.lstrip()
        if not s:
            return 0
            
        num, sign, i = 0, 1, 0
        if s[0] in "+-":
            sign = 1 if s[0] == "+" else -1
            i = 1

        while i < len(s) and s[i].isdigit():
            num = num * 10 + (ord(s[i]) - ord("0"))
            i += 1

        INT_MAX, INT_MIN = 2**31 - 1, -(2**31)
        val = sign * num

        if val > INT_MAX:
            return INT_MAX
        if val < INT_MIN:
            return INT_MIN
        return val
