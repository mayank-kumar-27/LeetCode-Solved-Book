class Solution {
    public int findMinArrowShots(int[][] p) {
        Arrays.sort(p, (a, b) -> Integer.compare(a[1], b[1]));
        int n = 1, x = p[0][1];
        for (int[] a : p) {
            if (a[0] > x) { n++; x = a[1]; }
        } return n;
    }
}