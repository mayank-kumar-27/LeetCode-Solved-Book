class Solution {
    public int sortPermutation(int[] arr) {
        int n = arr.length, r = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            if (arr[i] == i) continue;
            r &= arr[i];
        } return r == Integer.MAX_VALUE ? 0 : r;
    }
}