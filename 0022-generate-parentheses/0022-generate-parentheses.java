class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> r = new ArrayList<>();
        f(r, "", n, n);
        return r;
    }
    void f(List<String> r, String s, int o, int c) {
        if (o == 0 && c == 0) {
            r.add(s); return;
        }
        if (o > 0) f(r, s + "(", o - 1, c);
        if (c > o) f(r, s + ")", o, c - 1);
    }
}