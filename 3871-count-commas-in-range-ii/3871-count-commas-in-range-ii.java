class Solution {
    public long countCommas(long n) {
        long p = 1000, r = 0;
        while (p <= n) {
            r += n - p + 1; p *= 1000;
        } return r;
    }
}