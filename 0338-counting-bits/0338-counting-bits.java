class Solution {
    public int[] countBits(int n) {
        int[] r = new int[n + 1];
        for (int i = 1; i <= n; i++) r[i] = r[i / 2] + (i % 2);
        return r;
    }
}