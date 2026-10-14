class Solution {
    public String maxSumOfSquares(int n, int s) {
        if (s > 9 * n) return "";
        int r = s % 9;
        StringBuilder a = new StringBuilder();
        int ns = s / 9;
        for (int i = 0; i < ns; i++) a.append('9');
        if (r > 0) a.append((char) ('0' + r));
        int zeros = n - a.length();
        for (int i = 0; i < zeros; i++) a.append('0');
        return a.toString();
    }
}