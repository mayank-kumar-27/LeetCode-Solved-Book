class Solution {
    private Set<String> set = new HashSet<>();
    private void f(String s, int i, int l, int r, int lr, int rr, StringBuilder sb) {
        if (i == s.length()) {
            if (lr == 0 && rr == 0) set.add(sb.toString());
            return;
        }
        char c = s.charAt(i);
        int n = sb.length();
        if ((c == '(' && lr > 0) || (c == ')' && rr > 0)) {
            f(s, i + 1, l, r,
              lr - (c == '(' ? 1 : 0),
              rr - (c == ')' ? 1 : 0), sb);
        }
        sb.append(c);
        if (c != '(' && c != ')') {
            f(s, i + 1, l, r, lr, rr, sb);
        } else if (c == '(') {
            f(s, i + 1, l + 1, r, lr, rr, sb);
        } else if (r < l) {
            f(s, i + 1, l, r + 1, lr, rr, sb);
        }
        sb.deleteCharAt(n);
    }

    public List<String> removeInvalidParentheses(String s) {
        int l = 0, r = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                l++;
            } else if (c == ')') {
                if (l == 0) r++;
                else l--;
            }
        }
        f(s, 0, 0, 0, l, r, new StringBuilder());
        return new ArrayList<>(set);
    }
}