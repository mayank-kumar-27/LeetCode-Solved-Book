int minElement(int* nums, int n) {
    int m = INT_MAX;
    for (int i = 0; i < n; i++) {
        int s = 0;
        while (nums[i] > 0) { s += nums[i] % 10; nums[i] /= 10; }
        nums[i] = s;
        m = nums[i] < m ? nums[i] : m;
    }
    return m;
}
