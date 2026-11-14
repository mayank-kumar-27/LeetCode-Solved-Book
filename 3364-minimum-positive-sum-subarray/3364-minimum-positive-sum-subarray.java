class Solution {
    public int minimumSumSubarray(List<Integer> a, int l, int r) {
        int n = a.size(), m = Integer.MAX_VALUE;
        for (int k = l; k <= r; k++) for (int i = 0, s = 0; i < n; i++) {
            s += a.get(i) - (i >= k ? a.get(i - k) : 0);
            if (i >= k - 1 && s > 0 && s < m) m = s;
        } return m == Integer.MAX_VALUE ? -1 : m;
    }
}