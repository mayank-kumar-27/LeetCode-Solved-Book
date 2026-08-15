class Solution {
    public int longestSubsequence(int[] a) {
        int x = 0, m = 0;
        for (int v : a) { x ^= v; m |= v; }
        if (x != 0) return a.length;
        if (m == 0) return 0;
        return a.length - 1;
    }
}