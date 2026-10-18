class Solution {
    long mod = (long) 1e9 + 7;
    long[][] t;
    public int numOfWays(int[] nums) {
        int n = nums.length;
        t = new long[n][n];
        for (int i = 0; i < n; i++) {
            t[i][0] = t[i][i] = 1;
            for (int j = 1; j < i; j++) t[i][j] = (t[i-1][j-1] + t[i-1][j]) % mod;
        }
        return (int) ((dfs(Arrays.stream(nums).boxed().toList()) - 1 + mod) % mod);
    }
    long dfs(List<Integer> a) {
        int n = a.size();
        if (n < 3) return 1;
        List<Integer> l = new ArrayList<>(), r = new ArrayList<>();
        for (int i = 1; i < n; i++)
            if (a.get(i) < a.get(0)) l.add(a.get(i));
            else r.add(a.get(i));
        return dfs(l) * dfs(r) % mod * t[n-1][l.size()] % mod;
    }
}