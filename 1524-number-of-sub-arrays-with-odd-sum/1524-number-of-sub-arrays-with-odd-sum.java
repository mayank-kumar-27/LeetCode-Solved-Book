class Solution {
    public int numOfSubarrays(int[] arr) {
        int m = 1_000_000_007, s = 0, o = 0, e = 1, c = 0;
        for (int n : arr) {
            s += n;
            if (s % 2 == 0) { c = (c + o) % m; e++; } 
            else { c = (c + e) % m; o++; }
        } return c;
    }
}