class Solution {
    public int minMergedInteger(int[] a) {
        int m = Integer.MAX_VALUE, n = a.length;
        for (int i = 0; i < n; i += 2) {
            int c = Integer.parseInt(Integer.toString(a[i]) + Integer.toString(a[i + 1]));
            m = m < c ? m : c;
        } return m;
    }
}