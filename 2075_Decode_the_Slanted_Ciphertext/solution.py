class Solution:
    def decodeCiphertext(self, e: str, r: int) -> str:
        if not e or r == 0: return ""
        c = len(e) // r
        m = [list(e[i * c : (i + 1) * c]) for i in range(r)]
        res = []
        for s in range(c):
            i, j = 0, s
            while i < r and j < c:
                res.append(m[i][j])
                i += 1
                j += 1
        return "".join(res).rstrip()
