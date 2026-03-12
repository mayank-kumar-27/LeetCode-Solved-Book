class D:
    def __init__(s, n):
        s.p, s.r, s.c = list(range(n)), [0] * n, n

    def f(s, x):
        if s.p[x] != x:
            s.p[x] = s.f(s.p[x])
        return s.p[x]

    def u(s, a, b):
        x, y = s.f(a), s.f(b)
        if x == y:
            return 0
        if s.r[x] < s.r[y]:
            x, y = y, x
        s.p[y] = x
        s.r[x] += s.r[x] == s.r[y]
        s.c -= 1
        return 1


class Solution:
    def C(s, n, e, k, x):
        d = D(n)
        for u, v, w, m in e:
            if m and (w < x or not d.u(u, v)):
                return 0
        for u, v, w, m in e:
            if not m and w >= x:
                d.u(u, v)
        y = 0
        for u, v, w, m in e:
            if not m and w < x <= 2 * w and d.u(u, v):
                y += 1
                if y > k:
                    return 0
        return d.c == 1

    def maxStability(s, n, e, k):
        d = D(n)
        for u, v, w, m in e:
            if m and not d.u(u, v):
                return -1
        l, h, a = 1, 200000, -1
        while l <= h:
            m = (l + h) // 2
            if s.C(n, e, k, m):
                a, l = m, m + 1
            else:
                h = m - 1
        return a