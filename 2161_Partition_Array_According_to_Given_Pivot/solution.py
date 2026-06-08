class Solution:
    def pivotArray(self, arr: List[int], p: int) -> List[int]:
        l, g, e = [], [], []
        for n in arr:
            if n > p:
                g.append(n)
            elif n < p:
                l.append(n)
            else:
                e.append(n)
        return l + e + g
