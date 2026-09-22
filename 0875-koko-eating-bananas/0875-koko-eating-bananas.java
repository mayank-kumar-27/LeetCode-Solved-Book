class Solution {
    public int minEatingSpeed(int[] p, int h) {
        int l = 1, r = 0;
        for (int x : p) r = Math.max(r, x);
        while (l < r) {
            int m = l + (r - l) / 2;
            long t = 0;
            for (int x : p) t += (x + m - 1) / m;
            if (t <= h) r = m;
            else l = m + 1;
        } return l;
    }
}