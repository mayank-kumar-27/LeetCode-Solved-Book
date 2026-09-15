class Solution {
    public int maxPalindromes(String s, int k) {
        int n = s.length();
        boolean[][] p = new boolean[n][n];
        for (int l = 1; l <= n; l++) for (int i = 0; i + l <= n; i++) {
            int j = i + l - 1;
            p[i][j] = s.charAt(i) == s.charAt(j) && (l <= 2 || p[i + 1][j - 1]);
        }
        int[] d = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            d[i] = d[i - 1];
            for (int j = 0; j + k <= i; j++)
            if (p[j][i - 1]) d[i] = Math.max(d[i], d[j] + 1);
        } return d[n];
    }
}