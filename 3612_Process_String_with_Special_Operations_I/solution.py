class Solution:
    def processStr(self, s: str) -> str:
        r = []
        for ch in s:
            if ch == "*":
                if r: r.pop()
            elif ch == "#":
                r += r.copy()
            elif ch == "%":
                r = r[::-1]
            else:
                r.append(ch)
        return "".join(r)
