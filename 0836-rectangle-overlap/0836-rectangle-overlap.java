class Solution {
    public boolean isRectangleOverlap(int[] a, int[] b) {
        return Math.min(a[2], b[2]) > Math.max(a[0], b[0]) && Math.min(a[3], b[3]) > Math.max(a[1], b[1]);
    }
}