class Solution:
    def earliestFinishTime(self, a, b, c, d):
        def f(s1, t1, s2, t2):
            x = min(s1[i] + t1[i] for i in range(len(s1)))
            y = min(max(s2[i], x) + t2[i] for i in range(len(s2)))
            return y
        return min(f(a, b, c, d), f(c, d, a, b))
