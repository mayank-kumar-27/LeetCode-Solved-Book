class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        h, a, s = healths[:], [True]*len(positions), []
        for i in sorted(range(len(positions)), key=lambda i: positions[i]):
            if directions[i] == 'R':
                s.append(i)
            else:
                while s:
                    t = s[-1]
                    if h[t] == h[i]: a[t] = a[i] = False; s.pop(); break
                    elif h[t] > h[i]: a[i] = False; h[t] -= 1; break
                    else: a[t] = False; s.pop(); h[i] -= 1
        return [h[i] for i in range(len(positions)) if a[i]]