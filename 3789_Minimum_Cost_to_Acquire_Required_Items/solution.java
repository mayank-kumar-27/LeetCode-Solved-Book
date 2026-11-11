class Solution {
    public long minimumCost(int a, int b, int c, int x, int y) {
        long p = Math.min(x, y);
        return p * Math.min(c, (long) a + b)
             + (x - p) * Math.min(a, c)
             + (y - p) * Math.min(b, c);
    }
}
