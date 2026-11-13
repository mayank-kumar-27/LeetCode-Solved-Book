class Solution {
    public long countNonDecreasingSubarrays(int[] a, int k) {
        int n = a.length, r = n - 1;
        long s = 0, o = 0;
        Deque<int[]> d = new ArrayDeque<>();
        for (int l = n - 1; l >= 0; l--) {
            int v = a[l], c = 1;
            while (!d.isEmpty() && d.peekFirst()[0] < v) {
                int[] x = d.pollFirst();
                o += (long) (v - x[0]) * x[1];
                c += x[1];
            }
            d.offerFirst(new int[] { v, c });
            while (o > k) {
                int[] t = d.peekLast();
                o -= t[0] - a[r--];
                if (--t[1] == 0) d.pollLast();
            }
            s += r - l + 1;
        } return s;
    }
}