class Solution {
    public int maxSubarrayLength(int[] a, int k) {
        Map<Integer, Integer> m = new HashMap<>();
        int l = 0, ans = 0;
        for (int r = 0; r < a.length; r++) {
            m.put(a[r], m.getOrDefault(a[r], 0) + 1);
            while (m.get(a[r]) > k) {
                m.put(a[l], m.get(a[l]) - 1);
                l++;
            }
            ans = Math.max(ans, r - l + 1);
        } return ans;
    }
}