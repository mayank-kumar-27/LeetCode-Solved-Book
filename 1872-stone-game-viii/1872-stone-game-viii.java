class Solution {
    public int stoneGameVIII(int[] s) {
        int n = s.length;
        for (int i = 1; i < n; i++) s[i] += s[i - 1];
        int a = s[n - 1];
        for (int i = n - 2; i >= 1; i--) a = Math.max(a, s[i] - a);
        return a;
    }
}