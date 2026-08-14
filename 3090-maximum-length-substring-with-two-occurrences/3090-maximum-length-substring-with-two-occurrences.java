class Solution {
    public int maximumLengthSubstring(String s) {
        int[] a = new int[26];
        int l = 0, r = 0, ans = 0;
        while (r < s.length()) {
            a[s.charAt(r++) - 'a']++;
            while (a[s.charAt(r - 1) - 'a'] > 2) a[s.charAt(l++) - 'a']--;
            ans = Math.max(ans, r - l);
        } return ans;
    }
}