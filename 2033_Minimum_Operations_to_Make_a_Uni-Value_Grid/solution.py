class Solution:
    def minOperations(self, grid, x):
        arr = []
        a = 0
        for r in grid:
            for n in r:
                arr.append(n)
        arr.sort()
        l = len(arr)
        n = arr[l // 2]
        for i in arr:
            if i % x != n % x:
                return -1
            a += abs(n - i) // x
        return a
