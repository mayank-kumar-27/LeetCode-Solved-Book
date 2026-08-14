class Solution {
    public int findJudge(int n, int[][] t) {
        int[] a = new int[n + 1];
        for (int[] x : t) { a[x[0]]--; a[x[1]]++; }
        for (int i = 1; i <= n; i++) if (a[i] == n - 1) return i;
        return -1;
    }
}