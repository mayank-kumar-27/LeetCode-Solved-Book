class Solution {
    public int singleNumber(int[] a) {
        int x = 0, y = 0;
        for (int n : a) {
            x = (x ^ n) & ~y;
            y = (y ^ n) & ~x;
        }
        return x;
    }
}