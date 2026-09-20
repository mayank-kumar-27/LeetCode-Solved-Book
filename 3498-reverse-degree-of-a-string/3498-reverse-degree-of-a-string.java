class Solution {
    public int reverseDegree(String s) {
        int r = 0;
        for (int i = 1; i <= s.length(); i++) r += (26 - (s.charAt(i - 1) - 'a')) * i;
        return r;
    }
}