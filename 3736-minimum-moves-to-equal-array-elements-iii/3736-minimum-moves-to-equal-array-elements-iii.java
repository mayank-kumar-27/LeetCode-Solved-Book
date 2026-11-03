class Solution {
    public int minMoves(int[] a) {
        int m = Integer.MIN_VALUE, r = 0;
        for (int n : a) m = m > n ? m : n;
        for (int n : a) r += m - n;
        return r;
    }
}