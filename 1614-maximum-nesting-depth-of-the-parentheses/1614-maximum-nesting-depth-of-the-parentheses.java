class Solution {
    public int maxDepth(String s) {
        int r = 0;
        Stack<Character> st = new Stack<Character>();
        for (Character c : s.toCharArray()) {
            if (c == '(') st.push(c);
            else if (c == ')') st.pop();
            r = Math.max(r, st.size());
        } return r;
    }
}