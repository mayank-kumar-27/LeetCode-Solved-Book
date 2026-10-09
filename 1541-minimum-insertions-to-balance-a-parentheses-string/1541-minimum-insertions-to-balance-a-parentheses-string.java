class Solution {
    public int minInsertions(String s) {
        Stack<Character> a = new Stack<>();
        int b = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(') a.push('(');
            else {
                if (i + 1 < n && s.charAt(i + 1) == ')') i++;
                else b++;
                if (!a.isEmpty()) a.pop();
                else b++;
            }
        } return b + a.size() * 2;
    }
}