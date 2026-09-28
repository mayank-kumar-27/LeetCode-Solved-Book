class Solution {
    public int findDuplicate(int[] nums) {
        int i = 0, j = 0;
        while (nums[j] != -1) {
            j = nums[i];
            nums[i] = -1;
            i = j;
        } return j;
    }
}