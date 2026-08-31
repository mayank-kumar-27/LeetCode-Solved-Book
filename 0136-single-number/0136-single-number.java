class Solution {
    public int singleNumber(int[] a) {
        int r = 0;
        for (int i = 0; i < a.length; i++) r ^= a[i];
        return r;
    }
}