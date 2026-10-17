class Solution {
    public int minSwaps(int[] nums) {
        int n = nums.length;
        int[] s = new int[n];
        for (int i = 0; i < n; i++) {
            int x = nums[i], sum = 0;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            } s[i] = sum;
        }
        Integer[] idx = new Integer[n];
        for (int i = 0; i < n; i++) idx[i] = i;
        Arrays.sort(idx, (a, b) -> {
            if (s[a] != s[b]) return Integer.compare(s[a], s[b]);
            return Integer.compare(nums[a], nums[b]);
        });
        int[] p = new int[n];
        for (int i = 0; i < n; i++) p[idx[i]] = i;
        boolean[] v = new boolean[n];
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                c++;
                int j = i;
                while (!v[j]) {
                    v[j] = true;
                    j = p[j];
                }
            }
        } return n - c;
    }
}