class Solution {
    public boolean sumGame(String s) {
        int n = s.length(), m = n / 2;
        int a = 0, b = 0, c = 0, d = 0;
        for (int i = 0; i < m; i++) {
            if (s.charAt(i) == '?') a++;
            else c += s.charAt(i) - '0';
        }
        for (int i = m; i < n; i++) {
            if (s.charAt(i) == '?') b++;
            else d += s.charAt(i) - '0';
        }
        if ((a + b) % 2 != 0) return true;
        return c - d != (b - a) / 2 * 9;
    }
}