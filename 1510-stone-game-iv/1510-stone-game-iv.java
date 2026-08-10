class Solution {
    public boolean winnerSquareGame(int n) {
        boolean[] d = new boolean[n + 1];
        for (int i = 1; i <= n; i++) for (int j = 1; j * j <= i; j++)
        if (!d[i - j * j]) { d[i] = true; break; }
        return d[n];
    }
}