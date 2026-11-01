class Solution {
    public int minMoves(int[] a) {
        int m = a[0], s = 0;
        for (int x : a) m = Math.min(m, x);
        for (int x : a) s += x - m;
        return s;
    }
}