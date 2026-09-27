class Solution {
    public String reverseParentheses(String s) {
        Stack<Integer> st = new Stack<>();
        StringBuilder r = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (c == '(') st.push(r.length());
            else if (c == ')') {
                int i = st.pop();
                rev(r, i, r.length() - 1);
            } else r.append(c);
        } return r.toString();
    }
    private void rev(StringBuilder s, int i, int j) {
        while (i < j) {
            char t = s.charAt(i);
            s.setCharAt(i++, s.charAt(j));
            s.setCharAt(j--, t);
        }
    }
}