class Solution {
    public int minMoves(int[] a) {
        int m = Integer.MIN_VALUE, s = 0;
        for (int n : a) { m = m > n ? m : n; s += n; }
        return a.length * m - s;
    }
}