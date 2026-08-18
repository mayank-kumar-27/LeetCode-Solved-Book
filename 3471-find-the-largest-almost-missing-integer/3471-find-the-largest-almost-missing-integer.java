class Solution {
    public int largestInteger(int[] nums, int k) {
        int[] c = new int[51];
        for (int i = 0; i <= nums.length - k; i++) {
            boolean[] v = new boolean[51];
            for (int j = i; j < i + k; j++) v[nums[j]] = true;
            for (int x = 0; x <= 50; x++) if (v[x]) c[x]++;
        }
        for (int x = 50; x >= 0; x--) if (c[x] == 1) return x;
        return -1;
    }
}