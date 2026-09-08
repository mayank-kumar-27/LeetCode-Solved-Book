class Solution {
    public int longestPalindrome(String s) {
        int[] a = new int[128];
        int n = 0;
        for (char c : s.toCharArray()) a[c]++;
        for (int x : a) n += x / 2 * 2;
        return n < s.length() ? n + 1 : n;

    }
}