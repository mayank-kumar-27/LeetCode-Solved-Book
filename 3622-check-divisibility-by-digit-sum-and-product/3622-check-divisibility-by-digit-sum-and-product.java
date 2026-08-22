class Solution {
    public boolean checkDivisibility(int n) {
        int x = n, s = 0, p = 1;
        while (x > 0) {
            int d = x % 10;
            s += d; p *= d;
            x /= 10;
        } return n % (s + p) == 0;
    }
}