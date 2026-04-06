class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        o = {(x, y) for x, y in obstacles}
        D = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        d = x = y = r = 0

        for c in commands:
            if c == -1: d = (d + 1) % 4
            elif c == -2: d = (d + 3) % 4
            else:
                a, b = D[d]
                for _ in range(c):
                    if (x + a, y + b) in o: break
                    x += a
                    y += b
                    r = max(r, x * x + y * y)
        return r
