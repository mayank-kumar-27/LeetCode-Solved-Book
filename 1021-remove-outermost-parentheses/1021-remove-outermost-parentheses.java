class Solution {
    public String removeOuterParentheses(String s) {
        StringBuilder a = new StringBuilder();
        int d = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') { if (d++ > 0) a.append(c); }
            else { if (--d > 0) a.append(c); }
        } return a.toString();
    }
}