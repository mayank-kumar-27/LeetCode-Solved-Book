class Solution {
    public int[] resultArray(int[] nums) {
        int n = nums.length;
        int[] a = new int[n], b = new int[n];
        int i = 0, j = 0;
        a[i++] = nums[0];
        b[j++] = nums[1];
        for (int k = 2; k < n; k++) {
            if (a[i - 1] > b[j - 1]) a[i++] = nums[k];
            else b[j++] = nums[k];
        }
        int[] r = new int[n];
        System.arraycopy(a, 0, r, 0, i);
        System.arraycopy(b, 0, r, i, j);
        return r;
    }
}