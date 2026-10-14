class Solution {
    public int[] searchRange(int[] arr, int t) {
        int l = 0, h = arr.length - 1, ft = -1, lt = -1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (arr[m] >= t) h = m - 1;
            else l = m + 1;
            if (arr[m] == t) ft = m;
        }
        if (ft == -1) return new int[] { -1, -1 };

        l = 0; h = arr.length - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (arr[m] <= t) l = m + 1;
            else h = m - 1;
            if (arr[m] == t) lt = m;
        } return new int[] { ft, lt };
    }
}