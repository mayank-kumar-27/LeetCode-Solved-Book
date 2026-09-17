class Solution {
    public int tribonacci(int n) {
        int a = 0, b = 1, c = 1;
        for (int i = 3; i <= n; i++) {
            int d = a + b + c;
            a = b; b = c; c = d;
        } return n == 0 ? a : n == 1 ? b : c;
    }
}