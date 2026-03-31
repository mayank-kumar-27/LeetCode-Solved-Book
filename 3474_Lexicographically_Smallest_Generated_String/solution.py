class Solution:
    def generateString(self, s: str, t: str) -> str:
        n, m = len(s), len(t)
        r = ['?'] * (n + m - 1)

        for i, b in enumerate(s):
            if b != 'T': continue
            for j, c in enumerate(t):
                if r[i+j] not in ('?', c): return ""
                r[i+j] = c

        q, r = r[:], ['a' if c == '?' else c for c in r]

        for i, b in enumerate(s):
            if b != 'F' or ''.join(r[i:i+m]) != t: continue
            for j in range(i+m-1, i-1, -1):
                if q[j] == '?':
                    r[j] = 'b'
                    break
            else: return ""
            
        return ''.join(r)