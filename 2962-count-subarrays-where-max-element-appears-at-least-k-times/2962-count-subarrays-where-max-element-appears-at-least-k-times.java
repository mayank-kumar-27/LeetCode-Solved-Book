class Solution {
    public long countSubarrays(int[] nums, int k) {
        int m = nums[0], c = 0, l = 0;
        long ans = 0;
        for (int n : nums) m = m > n ? m : n;
        for (int r = 0; r < nums.length; r++) {
            if (nums[r] == m) c++;
            while (c >= k) {
                if (nums[l] == m) c--;
                l++;
            } ans += l;
        } return ans;
    }
}