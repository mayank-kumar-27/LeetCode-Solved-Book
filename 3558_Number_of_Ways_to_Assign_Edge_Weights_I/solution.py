class Solution:
    M = 10**9 + 7
    def dfs(self, g: list, x: int, f: int) -> int:
        m = 0
        for y in g[x]:
            if y == f:
                continue
            m = max(m, self.dfs(g, y, x) + 1)
        return m
    def assignEdgeWeights(self, edges: List[List[int]]) -> int:
        n = len(edges) + 1
        g = [[] for _ in range(n + 1)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        m = self.dfs(g, 1, 0)
        return pow(2, m - 1, self.M)
