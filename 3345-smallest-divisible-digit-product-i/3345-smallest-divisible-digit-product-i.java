class Solution {
    public int smallestNumber(int n, int t) {
        while (true) {
            int x = n, p = 1;
            while (x > 0) { p *= x % 10; x /= 10; }
            if (p % t == 0) return n; n++;
        }
    }
}