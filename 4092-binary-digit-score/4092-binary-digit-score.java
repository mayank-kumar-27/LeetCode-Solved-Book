class Solution {
    private int count(String s) {
        int r = 0;
        for (int i = 0; i < s.length(); i++) if (s.charAt(i) == '1') r++;
        return r;
    }
    public int calculateScore(int a, int b) {
        String s = Integer.toBinaryString(a), t = Integer.toBinaryString(b);
        int u = count(s), v = count(t);
        return u >= v ? u * v : v / u;
    }
}