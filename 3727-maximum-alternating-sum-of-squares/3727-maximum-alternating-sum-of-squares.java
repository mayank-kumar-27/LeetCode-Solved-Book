class Solution {
    public long maxAlternatingSum(int[] arr) {
        int n = arr.length; long r = 0;
        for (int i = 0; i < n; i++) arr[i] = arr[i] * arr[i];
        Arrays.sort(arr);
        for (int i = 0; i < n / 2; i++) { r -= arr[i]; r += arr[n - 1 - i]; }
        if (n % 2 != 0) r += arr[n / 2];
        return r;
    }
}