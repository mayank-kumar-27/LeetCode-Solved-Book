class Solution {
    public int minMoves2(int[] a) {
        Arrays.sort(a);
        int m = a[a.length / 2], c = 0;
        for (int x : a) c += Math.abs(x - m);
        return c;
    }
}