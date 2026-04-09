class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        n, M, lim = len(nums), 10**9 + 7, math.isqrt(len(nums))
        lk = defaultdict(list)
        for q in queries:
            l, r, k, v = q
            if k >= lim:
                for i in range(l, r + 1, k):
                    nums[i] = nums[i] * v % M
            else:
                lk[k].append(q)
        for k, ql in lk.items():
            d = [1] * n
            for l, r, _, v in ql:
                d[l] = d[l] * v % M
                if (x := l + ((r - l) // k + 1) * k) < n:
                    d[x] = d[x] * pow(v, -1, M) % M
            for i in range(n):
                if i >= k:
                    d[i] = d[i] * d[i - k] % M
                nums[i] = nums[i] * d[i] % M
        return reduce(lambda a, b: a ^ b, nums)
