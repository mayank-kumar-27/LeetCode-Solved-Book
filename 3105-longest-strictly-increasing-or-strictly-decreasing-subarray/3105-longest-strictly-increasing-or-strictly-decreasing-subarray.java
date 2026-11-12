class Solution {
    public int longestMonotonicSubarray(int[] a) {
        int l = 1, d = 1, m = 1;
        for (int i = 1; i < a.length; i++) {
            if (a[i] > a[i - 1]) { l++; d = 1; } 
            else if (a[i] < a[i - 1]) { d++; l = 1; } 
            else { l = 1; d = 1; }
            int c = l > d ? l : d;
            m = m > c ? m : c;
        } return m;
    }
}