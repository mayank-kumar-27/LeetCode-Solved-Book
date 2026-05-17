from collections import deque

class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        n = len(arr)
        q = deque([start])
        v = [False] * n
        v[start] = True
        while q:
            i = q.popleft()
            if arr[i] == 0:
                return True
            f = i + arr[i]
            b = i - arr[i]
            if f < n and not v[f]:
                v[f] = True
                q.append(f)
            if b >= 0 and not v[b]:
                v[b] = True
                q.append(b)

        return False
