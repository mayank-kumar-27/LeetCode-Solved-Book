class Solution {
    public boolean isPerfectSquare(int n) {
        if (n < 2) return true;
        int l = 2, h = n / 2;
        while (l <= h) {
            int m = l + (h - l) / 2;
            long r = (long) m * m;
            if (r == n) return true;
            else if (r < n) l = m + 1;
            else h = m - 1;
        } return false;
    }
}