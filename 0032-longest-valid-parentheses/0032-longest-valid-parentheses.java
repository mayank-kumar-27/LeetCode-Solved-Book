class Solution {
    public int longestValidParentheses(String s) {
        int m = 0, l = 0, r = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(') l++;
            else r++;
            if (l == r) m = Math.max(m, 2 * r);
            else if (r > l) l = r = 0;
        }
        l = r = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s.charAt(i) == '(') l++;
            else r++;
            if (l == r) m = Math.max(m, 2 * l);
            else if (l > r) l = r = 0;
        } return m;
    }
}